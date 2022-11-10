/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:55:39 by yridgway          #+#    #+#             */
/*   Updated: 2022/11/10 21:06:50 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ":"));
		i++;
	}
	return (NULL);
}

int	check_path(char *prog, char *cmdpath)
{
	if (access(cmdpath, F_OK) == 0)
	{
		if (access(cmdpath, X_OK) == 0)
			return (0);
		return (ft_permission_denied(prog));
		free(cmdpath);
	}
	return (1);
}

char	*get_valid_path(char **env, char **prog)
{
	char	**paths;
	char	*cmd;
	char	*cmdpath;
	int		i;
	int		ext;

	i = 0;
	ext = 1;
	cmd = ft_strjoin("/", prog[0]);
	paths = ft_get_paths(env);
	if (!paths)
		return (NULL);
	cmdpath = ft_strjoin(paths[0], cmd);
	while (paths[i] && ext == 1)
	{
		free(cmdpath);
		cmdpath = ft_strjoin(paths[i], cmd);
		ext = check_path(prog[0], cmdpath);
		i++;
	}
	if (!paths[i] && ext == 1)
		ext = ft_command_not_found(prog[0]);
	if (ext == 0 && cmdpath)
	{
		free(cmd);
		return (cmdpath);
	}
	ft_free_arr(paths);
	free(cmd);
	free(cmdpath);
	ft_free_arr(prog);
	exit(ext);
	return (NULL);
}

void	ft_execute(char *cmd, char **env)
{
	char	**command;
	char	*validcmd;
	int		ext;

	ext = 1;
	command = ft_split(cmd, " ");
	if (!command || !command[0])
		validcmd = NULL;
	else if (command[0][0] == '.' || command[0][0] == '/'
		|| command[0][1] == '/')
	{
		validcmd = ft_strdup(command[0]);
		ext = check_path(validcmd, validcmd);
		if (ext == 1)
			ext = ft_no_such_file(validcmd);
	}
	else
		validcmd = get_valid_path(env, command);
	if (validcmd == NULL)
	{
		ft_free_arr(command);
		ext = ft_command_not_found(validcmd);
		exit(ext);
	}
	if (execve(validcmd, command, env) == -1)
	{
		free(validcmd);
		unlink(".temp_heredoc");
		ft_free_arr(command);
		exit(ext);
	}
}

void	ft_child(char *cmd, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_exit_msg("problem with pipe()");
	pid = fork();
	if (pid == -1)
		ft_exit_msg("problem with fork()");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_execute(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}
