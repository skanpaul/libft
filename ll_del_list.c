/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:31:04 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:31:06 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ll_del_list(t_elem **top_elem, void (*del_content)(void *))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *top_elem;
	ptr2 = NULL;
	if ((ptr1 == NULL) || (del_content == NULL))
		return ;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		ft_lstdelone(ptr1, del_content);
		ptr1 = ptr2;
	}
	ft_lstdelone(ptr1, del_content);
	*top_elem = NULL;
	return ;
}
