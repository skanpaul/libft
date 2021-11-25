/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:08:15 by ski               #+#    #+#             */
/*   Updated: 2021/11/15 13:08:17 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;	
	size_t	new_len;
	char	*new;

	if ((s1 == 0) | (s2 == 0))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_len = s1_len + s2_len + 1;
	new = (char *)malloc(new_len * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s1, s1_len);
	ft_memmove(new + s1_len, s2, s2_len);
	new[new_len - 1] = '\0';
	return (new);
}
