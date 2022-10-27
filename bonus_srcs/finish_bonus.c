/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:38:18 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/27 21:21:08 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	ft_exit_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
	exit(1);
}
