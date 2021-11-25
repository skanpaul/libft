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
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	if ((src < dst) & (len > 0))
	{
		i = len - 1;
		while (i > 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		*((char *)dst + i) = *((char *)src + i);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	return (dst);
}

// Test code:

// 	char *src = "thanks to @apellicc for this test !\r\n";
// 	char dst1[0xF0];

// 	int size = strlen(src);
// 	char *r1 = __builtin___memmove_chk (dst1, 
// src, size, __builtin_object_size (dst1, 0));
// 	char *r2 = ft_memmove(dst1, src, size);

// 	if (r1 != r2)
// 		exit(TEST_FAILED);
// 	r1 = __builtin___memmove_chk ("", "" - 1, 0, __builtin_object_size ("", 0));
// 	r2 = ft_memmove("", "" - 1, 0);
// 	if (r1 != r2)
// 		exit(TEST_FAILED);
// 	exit(TEST_SUCCESS);

/* -------------------- GITHUB -------------------------------*/
// void	*ft_memmove(void *s1, const void *s2, size_t len)
// {
// 	unsigned char	*dst;
// 	unsigned char	*src;
// 	unsigned int	i;

// 	dst = (unsigned char *)s1;
// 	src = (unsigned char *)s2;
// 	i = 0;
// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	if (dst < src)
// 	{
// 		while (i < len)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (0 < len--)
// 			dst[len] = src[len];
// 	}
// 	return (dst);
// }

/* --------------------- CODE LISIBLE ----------------------
{
	size_t i;
	char *ptr_dst;
	char *ptr_src;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (src < dst)
	{
		i = len - 1;
		while (i > 0)
		{
			ptr_dst[i] = ptr_src[i];
			i--;
		}
		ptr_dst[i] = ptr_src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
*/