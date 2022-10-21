/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/21 15:20:27 by yridgway         ###   ########.fr       */
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
	pipex->cmd1[0] = get_valid_path(env, pipex->cmd1[0]);
	close(pipex->pipefd[0]);
	dup2(pipex->pipefd[1], 1);
	close(pipex->pipefd[1]);
	if (execve(pipex->cmd1[0], pipex->cmd1, env) == -1)
		perror("execve(first_child): ");
}

void	second_child(t_pipex *pipex, char **env)
{
	pipex->cmd2[0] = get_valid_path(env, pipex->cmd2[0]);
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], 0);
	close(pipex->pipefd[0]);
	if (execve(pipex->cmd2[0], pipex->cmd2, env) == -1)
		perror("execve(second_child): ");
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	(void)ac;
	pipex = malloc(sizeof (t_pipex));
	if (!pipex || pipe(pipex->pipefd) == -1)
		return (0);
	pipex->cmd1 = ft_split(av[1], " ");
	pipex->cmd2 = ft_split(av[2], " ");
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first_child(pipex, env);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		second_child(pipex, env);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free_everything(pipex);
	return (0);
}
