/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:55:39 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/26 20:59:46 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*get_valid_path(char **env, char *prog)
{
	char	**paths;
	char	*cmd;
	char	*cmdpath;
	int		i;

	i = 0;
	cmd = ft_strjoin("/", prog);
	paths = ft_get_paths(env);
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		cmdpath = ft_strjoin(paths[i], cmd);
		if (access(cmdpath, X_OK) == 0)
		{
			free(cmd);
			return (cmdpath);
		}
		free(cmdpath);
		i++;
	}
	ft_error(prog);
	ft_free_arr(paths);
	free(cmd);
	return (NULL);
}

void	ft_execute(char *cmd, char **env)
{
	char	**command;
	char	*validcmd;

	command = ft_split(cmd, " ");
	if (command[0] && access(command[0], X_OK) != 0)
		validcmd = get_valid_path(env, command[0]);
	else
		validcmd = command[0];
	if (validcmd == NULL)
	{
		ft_free_arr(command);
		exit(0);
	}
	if (execve(validcmd, command, env) == -1)
	{
		//ft_putstr_fd(strerror(errno), 2);
		ft_free_arr(command);
		free(validcmd);
		exit(0);
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
		waitpid(pid, NULL, 0);
	}
}
