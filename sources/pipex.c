/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/21 20:02:46 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, char **av, int infd, int outfd)
{
	pipex->infd = infd;
	pipex->outfd = outfd;
	pipex->cmd1 = ft_split(av[2], " ");
	pipex->cmd2 = ft_split(av[3], " ");
	if (!pipex->cmd1 || !pipex->cmd2)
	{
		write(2, "problem with malloc of cmds\n", 28);
		exit(0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		infd;
	int		outfd;

	if (ac != 5)
		return (write(2, "Wrong number of arguments\n", 27), 0);
	infd = open(av[1], O_RDONLY);
	outfd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infd == -1 || outfd == -1)
		return (write(2, "Problem opening/creating files\n", 31), 0);
	pipex = malloc(sizeof (t_pipex));
	if (!pipex || pipe(pipex->pipefd) == -1)
		return (write(2, "Pipe failure\n", 13), 0);
	init_pipex(pipex, av, infd, outfd);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first_child(pipex, env);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		second_child(pipex, env);
	close_free(pipex);
	ft_end(pipex);
	return (0);
}
