/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:24:18 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/14 17:05:21 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*char	*ft_itoa(int n)
{
	char	*num;

	if (n == -2147483648)
		return ("-2147483648");
	num = malloc(2 * sizeof (char));
	if (n < 0)
	{
		num[0] = '-';
		num[1] = '\0';
		return (ft_strjoin(num, ft_itoa(-n)));
	}
	if (n > 9)
	{
		num = ft_strjoin(num, ft_itoa(n / 10));
		num = ft_strjoin(num, ft_itoa(n % 10));
	}
	else
	{
		num[0] = n + '0';
		num[1] = '\0';
	}
	return (num);
}*/

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*result;

	sign = 1;
	i = ft_numlen(n);
	if (n <= 0)
	{
		sign = -1;
		i++;
	}
	result = malloc((i + 1) * sizeof (char));
	if (!result)
		return (NULL);
	result[0] = '-';
	if (n == 0)
		result[0] = '0';
	result[i] = '\0';
	while (--i >= 0 && n != 0)
	{
		result[i] = (n % 10) * sign + 48;
		n /= 10;
	}
	return (result);
}
