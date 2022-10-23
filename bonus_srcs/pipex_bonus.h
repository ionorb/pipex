/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:51 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/21 19:57:00 by yridgway         ###   ########.fr       */
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
void	ft_exit_msg(char *msg, t_pipex *pipex);
void	close_free(t_pipex *pipex);
void	ft_free_arr(char **cmd);
void	ft_end(t_pipex *pipex);

//children
void	first_child(t_pipex *pipex, char **env);
void	second_child(t_pipex *pipex, char **env);

#endif
