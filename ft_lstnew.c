/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:37:08 by ski               #+#    #+#             */
/*   Updated: 2021/11/22 16:37:22 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
