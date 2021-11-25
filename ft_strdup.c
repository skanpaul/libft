/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:59:37 by ski               #+#    #+#             */
/*   Updated: 2021/11/13 12:59:40 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	mem_len;
	char	*new;

	mem_len = ft_strlen(s1) + 1;
	new = (char *)malloc(mem_len * sizeof(char));
	if (new == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
