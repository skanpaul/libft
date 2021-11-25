/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:49:50 by ski               #+#    #+#             */
/*   Updated: 2021/11/09 11:49:53 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dst);
	if (dstsize < j)
		return (ft_strlen(src) + dstsize);
	if (dstsize - j > 0)
	{
		i = 0;
		while ((i < (dstsize - j - 1)) & (src[i] != '\0'))
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
	}
	return (ft_strlen(src) + j);
}
