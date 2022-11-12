/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/11/12 23:34:03 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkfd(int fd, int ext, char *extra)
{
	if (fd < 0)
	{
		ft_error(extra);
		exit(ext);
	}
}

int	ft_parse(int ac, char **av)
{
	int	fd;

	if (ac < 5)
		ft_exit_msg("Wrong number of arguments");
	fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	ft_checkfd(fd, 1, av[ac - 1]);
	return (fd);
}

int	main(int ac, char **av, char **env)
{
	int		infd;
	int		outfd;
	int		i;

	i = 1;
	outfd = ft_parse(ac, av);
	ft_checkfd(outfd, 0, NULL);
	infd = open(av[1], O_RDONLY);
	ft_checkfd(infd, 0, NULL);
	dup2(infd, 0);
	while (++i < ac - 2 && waitpid(0, NULL, 0))	
		ft_child(av[i], env);
	dup2(outfd, 1);
	close(outfd);
	close(infd);
	ft_execute(av[i], env);
	return (0);
}
