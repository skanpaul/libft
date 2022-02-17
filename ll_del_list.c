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
void	ll_del_list(t_elem *top_elem, void (*del_content)(void *))
{
	t_elem	*ptr;

	ptr = NULL;
	if ((top_elem == NULL) || (del_content == NULL))
		return ;
	while (top_elem->next != NULL)
	{
		ptr = top_elem->next;
		ll_del_elem(top_elem, del_content);
		top_elem = ptr;
	}
	ll_del_elem(top_elem, del_content);
	top_elem = NULL;
	return ;
}
