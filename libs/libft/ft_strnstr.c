/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:27:34 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:20:43 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] && i < len && little[j])
	{
		j = 0;
		while (i + j < len && big[i] && little[j] && (little[j] == big[i + j]))
			j++;
		i++;
	}
	if (little[j] != '\0')
		return (NULL);
	return ((char *)(big + i - 1));
}
