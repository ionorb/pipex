/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:31:26 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/24 15:38:37 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;
	t_list	*temp;

	node = (t_list *) malloc(sizeof (t_list));
	temp = node;
	node->content = content;
	node->next = NULL;
	return (temp);
}
