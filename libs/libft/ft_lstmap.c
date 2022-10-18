/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:34:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:19:30 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*item;

	cpy = NULL;
	while (lst)
	{
		item = ft_lstnew((*f)(lst->content));
		if (!item)
		{
			ft_lstclear(&cpy, del);
			return (NULL);
		}
		ft_lstadd_back(&cpy, item);
		lst = lst->next;
	}
	return (cpy);
}
