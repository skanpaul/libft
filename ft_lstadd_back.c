/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:36:08 by ski               #+#    #+#             */
/*   Updated: 2021/11/23 16:36:10 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
// void	ft_lstadd_back(t_list **alst, t_list *new)
// {
// 	if ((!alst) || (!new))
// 		return ;

// 	if (*alst == NULL)
// 		*alst = new;
// 	while (((*alst)->next) != NULL)
// 	{
// 		*alst = (*alst)->next;
// 	}
// 	(*alst)->next = new;
// 	new->next = NULL;	
// }

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	
	
	if ((!alst) || (!new))
		return ;

	if (ptr == NULL)
		ptr = new;

	while ((ptr->next) != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
	// new->next = NULL;	
}
