/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:55:39 by yridgway          #+#    #+#             */
/*   Updated: 2022/11/09 20:10:57 by yridgway         ###   ########.fr       */
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

int	check_path(char *cmd, char **paths, char **prog, char *cmdpath)
{
	if (access(cmdpath, F_OK) == 0)
	{
		if (access(cmdpath, X_OK) == 0)
		{
			free(cmd);
			ft_free_arr(paths);
			return (0);
		}
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
	while (paths[i] && ext == 1)
	{
		cmdpath = ft_strjoin(paths[i], cmd);
		ext = check_path(cmd, paths, prog, cmdpath);
		i++;
	}
	if (!paths[i] && ext == 1)
		ext = ft_command_not_found(prog);
	if (ext == 0 && cmdpath)
		return (cmdpath);
	ft_free_arr(paths);
	free(cmd);
	ft_free_arr(prog);
	exit(ext);
	return (NULL);
}

void	ft_execute(char *cmd, char **env)
{
	char	**command;
	char	*validcmd;

	command = ft_split(cmd, " ");
//	printf("yogs: %s\n", command[0]);
	if (command && command[0])// && command[0][0] != '.')
	{
		validcmd = get_valid_path(env, command);
//		printf("yo: %s\n", validcmd);
		write(2, "sloo\n", 5);
	}
	else if (command && command[0])
		validcmd = ft_strdup(command[0]);
	else
		validcmd = NULL;
	if (validcmd == NULL)
	{
		ft_free_arr(command);
		write(2, "[4]\n", 4);
		exit(1);
	}
	if (execve(validcmd, command, env) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		free(validcmd);
		unlink(".temp_heredoc");
		ft_free_arr(command);
		write(2, "[5]\n", 4);
		exit(127);
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
