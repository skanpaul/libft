/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:02:22 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 11:02:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
t_elem	*ll_copy_list(t_elem *top_elem, void *(*f)(void *), void (*d)(void *))
{
	t_elem	*ptr;
	t_elem	*new_top_elem;
	t_elem	*new_elem;

	new_top_elem = NULL;
	if (top_elem == NULL)
		return (NULL);
	ptr = top_elem;
	while (ptr != NULL)
	{
		new_elem = ll_new_elem(f(ptr->content));
		if (new_elem == NULL)
		{
			if (new_top_elem != NULL)
				ll_del_list(&new_top_elem, d);

			return (NULL);
		}
		ll_add_elem_to_bottom(&new_top_elem, new_elem);
		ptr = ptr->next;
	}
	return (new_top_elem);
}
