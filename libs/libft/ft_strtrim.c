/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:26:09 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:20:50 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_getsize(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (ft_inset(s1[i], set))
		i++;
	if (!s1[i])
		return (0);
	while (s1[count + i])
		count++;
	count--;
	while (ft_inset(s1[count + i], set))
		count--;
	count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	size_t	size;

	i = 0;
	size = ft_getsize(s1, set);
	while (ft_inset(s1[i], set))
		i++;
	trimmed = ft_substr(s1, i, size);
	return (trimmed);
}
