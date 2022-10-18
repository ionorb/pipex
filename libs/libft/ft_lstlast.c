/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:24:38 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:19:28 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cpy;

	if (lst == NULL)
		return (NULL);
	cpy = lst;
	while (cpy->next != NULL)
		cpy = cpy->next;
	return (cpy);
}
