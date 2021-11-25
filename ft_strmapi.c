/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:53:19 by ski               #+#    #+#             */
/*   Updated: 2021/11/19 15:53:29 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*new;

	if ((s == NULL) | (f == NULL))
		return (NULL);
	s_len = ft_strlen(s);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	new[s_len] = '\0';
	i = 0;
	while (i < s_len)
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
