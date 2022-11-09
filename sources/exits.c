/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:27:36 by yridgway          #+#    #+#             */
/*   Updated: 2022/11/09 19:49:18 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_permission_denied(char **prog)
{
	ft_putstr_fd("zsh: permission denied: ", 2);
	ft_putstr_fd(prog[0], 2);
	write(2, "\n", 1);
	return (126);
}

int	ft_command_not_found(char **prog)
{
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(prog[0], 2);
	write(2, "\n", 1);
	return (127);
}
