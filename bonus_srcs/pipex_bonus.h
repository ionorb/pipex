/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:51 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/25 16:24:58 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "../libs/libft/libft.h"

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*validcmd1;
	char	*validcmd2;
	int		pipefd[2];
	int		infd;
	int		outfd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

//finish
void	ft_exit_msg(char *msg);
void	close_free(t_pipex *pipex);
void	ft_free_arr(char **cmd);
void	ft_end(t_pipex *pipex);

//children
void	ft_child(char *cmd, char **env);

void	ft_execute(char *cmd, char **env);
#endif
