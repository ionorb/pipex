/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:51 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/21 15:00:48 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "libs/libft/libft.h"

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	int		pipefd[2];
	int		infd;
	int		outfd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

//free
void	free_everything(t_pipex *pipex);
void	ft_free_arr(char **cmd);

#endif
