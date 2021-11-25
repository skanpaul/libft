/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:08:26 by ski               #+#    #+#             */
/*   Updated: 2021/11/23 10:08:29 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if ((alst != NULL) && (new != NULL))
	{
		new->next = *alst;
		*alst = new;
	}
}

// void	ft_lstadd_front_BBB(t_list **alst, t_list *new)
// {
// 	size_t i;

// 	if(!alst)
// 		return ;
	
// 	i = 0;	
// 	while (alst[i] != NULL)
// 		i++;

// 	while(i > 0)
// 	{
// 		alst[i + 1] = 	alst[i];
// 		i--;
// 	}
// 	alst[i + 1] = 	alst[i];
// 	alst[i] = new;
// 	new->next = alst[1];
// }