/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:34:57 by ski               #+#    #+#             */
/*   Updated: 2021/11/04 16:34:59 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	size;

	size = (int)dstsize;

	if (size - 1 > (int)sizeof(src))
		size = (int)sizeof(src) + 1;

	if (size == 0) 
		return (ft_strlen(src));
	i = 0;

	while ((i < size - 1) & (dst[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
