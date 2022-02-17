/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_add_elem_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:29 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 09:51:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ll_add_elem_to_top(t_elem *top_elem, t_elem *new_elem)
{
	if (top_elem == NULL)
		top_elem = new_elem;
	else
	{
		new_elem->next = top_elem;
		top_elem= new_elem;
	}
	return ;
}
