/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:35:30 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:19:50 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 1;
	if (lst == NULL)
		return (0);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
