/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:25:41 by ski               #+#    #+#             */
/*   Updated: 2021/11/11 20:25:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	j_max;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while ((haystack[i] != '\0') & (i <= len))
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			j_max = len - i ;
			while ((j < j_max) & (needle[j] == haystack[i + j])
				& (needle[j] != '\0'))
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
