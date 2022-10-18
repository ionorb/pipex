/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/18 18:41:56 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t	pidz;
	
	(void)ac;
	pidz = fork();
	if (pidz == -1)
	{
		perror("YOOOO: ");
		return (0);
	}
	if (pidz == 0)
	{
		printf("[%d]\n", pidz);
		execve(av[1], av + 1, env);
	}
	else
	{
		printf("[%d]\n", pidz);
		execve(av[1], av + 1, env);
	}
	return (0);
}
