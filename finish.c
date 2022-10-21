/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:38:18 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/21 16:30:49 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	write(1, "\n", 1);
	exit(0);
}

void	ft_free_arr(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	close_free(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	ft_free_arr(pipex->cmd1);
	ft_free_arr(pipex->cmd2);
}

void	ft_end(t_pipex *pipex, int infd, int outfd)
{
	close_free(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	close(infd);
	close(outfd);
}
