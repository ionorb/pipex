/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:44 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/19 17:11:08 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			printf("%s\n", env[i] + 5);
			return(ft_split(env[i] + 5, ":"));
		}
		i++;
	}
	return (NULL);
}

char	*get_valid_path(char **env)
{
	char	**paths;
	int		i;

	i = 0;
	paths = ft_get_paths(env);
	while (paths[i])
	{
		if (access(ft_strjoin(ft_strdup(paths[i]), "/push_swap_gui"), X_OK) == 0)
			return (ft_strjoin(ft_strdup(paths[i]), "/push_swap_gui"));
		i++;
	}
	free(paths);
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pidz;

	(void)ac;
	printf("valid: %s\n", get_valid_path(env));
	pidz = fork();
	if (pidz == -1)
	{
		perror("YOOOO: ");
		return (0);
	}
	if (pidz == 0)
	{
		printf("[%d]\n", pidz);
		execve(av[1], av + 1, env);
	}
	else
	{
		printf("[%d]\n", pidz);
		execve(av[1], av + 1, env);
	}
	return (0);
}
