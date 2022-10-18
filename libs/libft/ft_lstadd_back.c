/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:48:19 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/14 17:05:23 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst && *lst)
	{	
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else if (lst)
		*lst = new;
}
