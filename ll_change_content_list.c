/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_change_content_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:44:03 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:44:04 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ll_change_content_list(t_elem *top_elem, void (*f)(void *))
{
	t_elem	*ptr1;
	t_elem	*ptr2;

	ptr1 = top_elem;
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
