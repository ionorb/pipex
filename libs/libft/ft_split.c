/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:50:22 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/14 17:55:29 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isin(char s, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (s == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_len(char *s, char *str)
{
	int	k;
	int	len;

	k = 0;
	len = 0;
	while (s[k] && !ft_isin(s[k], str))
	{
		len++;
		k++;
	}
	return (len);
}

char	**ft_makearr(char *s, char *str)
{
	char	**arr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_isin(s[i], str))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_isin(s[i], str))
			i++;
	}
	arr = malloc((count + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	return (arr);
}

char	*ft_putword(char *s, char *str)
{
	char	*word;
	int		k;

	k = 0;
	word = malloc((ft_len(s, str) + 1) * sizeof (char));
	if (!word)
		return (NULL);
	while (s[k] && !ft_isin(s[k], str))
	{
		word[k] = s[k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

char	**ft_split(char *s, char *str)
{
	int		i;
	int		k;
	char	**arr;

	arr = ft_makearr(s, str);
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] && ft_isin(s[k], str))
			k++;
		if (s[k])
		{
			arr[i] = ft_putword((s + k), str);
			i++;
		}
		while (s[k] && !ft_isin(s[k], str))
			k++;
	}
	arr[i] = 0;
	return (arr);
}
