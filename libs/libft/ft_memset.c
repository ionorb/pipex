/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:18:57 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:20:10 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	ch = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ch + i) = c;
		i++;
	}
	return (s);
}
