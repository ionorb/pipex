/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/27 21:37:11 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *limiter)
{
	char	*str;
	int		fd;

	fd = open(".temp_heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	str = NULL;
	while (!str || ft_strncmp(limiter, str, ft_strlen(limiter)))
	{
		write(1, "heredoc> ", 9);
		free(str);
		str = get_next_line(0, 1);
		write(fd, str, ft_strlen(str));
	}
	free(str);
	close(fd);
}

int	ft_parse(int ac, char **av)
{
	int	fd;

	if (ac < 5 || (ft_strncmp("here_doc", av[1], 8) == 0 && ac < 6))
		ft_exit_msg("Wrong number of arguments");
	fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_exit_msg("unable to create output file");
	return (fd);
}

int	main(int ac, char **av, char **env)
{
	int		infd;
	int		outfd;
	int		i;

	i = 1;
	outfd = ft_parse(ac, av);
	if (ft_strncmp("here_doc", av[1], 8) == 0)
	{
		here_doc(av[2]);
		infd = open(".temp_heredoc", O_RDONLY);
		i++;
	}
	else
		infd = open(av[1], O_RDONLY);
	dup2(infd, 0);
	while (++i < ac - 2)
		ft_child(av[i], env);
	dup2(outfd, 1);
	close(outfd);
	close(infd);
	unlink(".temp_heredoc");
	ft_execute(av[i], env);
	return (0);
}
