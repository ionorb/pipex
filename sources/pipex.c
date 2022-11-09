/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/11/09 18:44:21 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	int	heredoc;

	if (ac < 5)
		ft_exit_msg("Wrong number of arguments");
	heredoc = ft_strncmp("here_doc", av[1], 8);
	if (!heredoc)
		fd = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_exit_msg("unable to create output file");
	return (fd);
}

void	ft_checkfd(int fd)
{
	if (fd < 0)
	{
		ft_error(NULL);
		write(2, "[2]\n", 4);
		exit(0);
	}
}

int	main(int ac, char **av, char **env)
{
	int		infd;
	int		outfd;
	int		i;

	i = 1;
	outfd = ft_parse(ac, av);
	ft_checkfd(outfd);
	if (ft_strncmp("here_doc", av[1], 8) == 0)
	{
		here_doc(av[2]);
		infd = open(".temp_heredoc", O_RDONLY);
		i++;
	}
	else
		infd = open(av[1], O_RDONLY);
	ft_checkfd(infd);
	dup2(infd, 0);
	while (++i < ac - 2 && waitpid(0, NULL, 0))
		ft_child(av[i], env);
	dup2(outfd, 1);
	close(outfd);
	close(infd);
	unlink(".temp_heredoc");
	ft_execute(av[i], env);
	write(2, "[3]\n", 4);
	return (0);
}
