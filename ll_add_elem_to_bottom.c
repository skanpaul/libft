/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_add_elem_to_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:00:08 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 10:00:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ll_add_elem_to_bottom(t_elem **top_elem, t_elem *new_elem)
{
	t_elem	*ptr;

	ptr = *top_elem;
	if (top_elem == NULL)
		return ;
	if (ptr == NULL)
	{
		*top_elem = new_elem;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_elem;
	return ;
}
