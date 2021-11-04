/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:09:01 by ski               #+#    #+#             */
/*   Updated: 2021/11/04 11:09:07 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	size_t	len_src;
	size_t	len_dst;
	char	*ptr_src;
	char	*ptr_dst;

	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	len_src = sizeof(ptr_src);
	len_dst = sizeof(ptr_dst);
	if (len > len_dst)
		len = len_dst;
	i = (int)len - 1;
	while (i >= 0)
	{
		ptr_dst[i] = ptr_src[i];
		i--;
	}		
	return (dst);
}
