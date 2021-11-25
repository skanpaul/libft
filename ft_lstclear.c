/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:25:39 by ski               #+#    #+#             */
/*   Updated: 2021/11/25 13:25:42 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *lst;
	ptr2 = NULL;
	if ((ptr1 == NULL) || (del == NULL))
		return ;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		ft_lstdelone(ptr1, del);
		ptr1 = ptr2;
	}
	ft_lstdelone(ptr1, del);
	*lst = NULL;
	return ;
}
