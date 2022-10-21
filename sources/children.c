/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:55:39 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/21 19:56:43 by yridgway         ###   ########.fr       */
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

char	*get_valid_path(char **env, char *prog)
{
	char	**paths;
	char	*cmd;
	char	*cmdpath;
	int		i;

	i = 0;
	cmd = ft_strjoin("/", prog);
	paths = ft_get_paths(env);
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
	ft_free_arr(paths);
	free(cmd);
	return (NULL);
}

void	first_child(t_pipex *pipex, char **env)
{
	pipex->validcmd1 = get_valid_path(env, pipex->cmd1[0]);
	if (pipex->validcmd1 == NULL)
		ft_exit_msg("first command not found", pipex);
	close(pipex->pipefd[0]);
	dup2(pipex->pipefd[1], 1);
	dup2(pipex->infd, 0);
	close(pipex->pipefd[1]);
	if (execve(pipex->validcmd1, pipex->cmd1, env) == -1)
	{
		perror("execve(first_child)");
		exit(0);
	}
}

void	second_child(t_pipex *pipex, char **env)
{
	pipex->validcmd2 = get_valid_path(env, pipex->cmd2[0]);
	if (pipex->validcmd2 == NULL)
		ft_exit_msg("second command not found", pipex);
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], 0);
	dup2(pipex->outfd, 1);
	close(pipex->pipefd[0]);
	if (execve(pipex->validcmd2, pipex->cmd2, env) == -1)
	{
		perror("execve(second_child)");
		exit(0);
	}
}
