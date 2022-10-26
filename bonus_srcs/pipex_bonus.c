/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/26 20:56:41 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *extra)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	if (extra)
	{
		write(2, ": ", 2);
		ft_putstr_fd(extra, 2);
	}
	write(2, "\n", 1);
}

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
		return (ft_error("infile"), 0);
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
