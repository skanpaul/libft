/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:49:16 by ski               #+#    #+#             */
/*   Updated: 2021/11/25 13:49:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = lst;
	ptr2 = NULL;
	if ((ptr1 == NULL) || (f == NULL))
		return ;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		f(ptr1->content);
		ptr1 = ptr2;
	}
	f(ptr1->content);
}
