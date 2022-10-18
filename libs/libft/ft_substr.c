/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:40:29 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:20:51 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) <= start)
	{
		str = (char *)malloc(sizeof (char));
		str[0] = '\0';
		return (str);
	}
	while (s[start + i] && i < len && start < ft_strlen(s))
		i++;
	str = (char *)malloc((i + 1) * sizeof (char));
	if (!str)
		return (NULL);
	j = i + 1;
	while (--j > 0)
		str[i - j] = s[start + (i - j)];
	str[i - j] = 0;
	return (str);
}
