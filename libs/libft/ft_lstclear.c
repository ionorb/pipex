/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:37:36 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:19:22 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	nxt = *lst;
	while (*lst != NULL)
	{
		nxt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxt;
	}
	*lst = NULL;
}
