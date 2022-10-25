/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/25 16:26:53 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	int		infd;
	int		outfd;
	int		i;

	if (ac < 5)
		return (write(2, "Wrong number of arguments\n", 27), 0);
	infd = open(av[1], O_RDONLY);
	outfd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infd == -1 || outfd == -1)
		return (write(2, "Problem opening/creating files\n", 31), 0);
	dup2(infd, 0);
	i = 1;
	while (++i < ac - 2)
		ft_child(av[i], env);
	dup2(outfd, 1);
	close(outfd);
	close(infd);
	ft_execute(av[ac - 2], env);
	return (0);
}
