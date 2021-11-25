/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:03:07 by ski               #+#    #+#             */
/*   Updated: 2021/11/25 14:03:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr1;
	t_list	*new_lst;
	t_list	*new;

	/* ---------------------------------------------------- */
	if ((lst == NULL) || (f == NULL) || (del == NULL))
		return (NULL);
	/* ---------------------------------------------------- */
	
	ptr1 = lst;
	while (ptr1 != NULL)
	{
		new = ft_lstnew(f(ptr1->content));
		if(new == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		ptr1 = ptr1->next;
	}
	return (new_lst);
}

/* ************************************************************************** */
// Paramètres
// #1. L’adresse du pointeur vers un élément.
// #2. L’adresse de la fonction à appliquer.
// 
// Valeur de retour
// La nouvelle liste. 
// NULL si l’allocation échoue.
// 
// Fonctions externes autorisées
// malloc, free 
//  
// Description
// Itère sur la liste lst et applique la fonction f au contenu de chaque élément. 
// Crée une nouvelle liste résultant des applications successives de f. 
// la fonction del est la pour detruire le contenu d un element si necessaire
