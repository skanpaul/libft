/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:24:30 by ski               #+#    #+#             */
/*   Updated: 2021/11/13 16:24:33 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	new_len;
	char	*new;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup("\0"));
	if (len > s_len)
		new_len = s_len - start + 1;
	else
		new_len = len + 1;
	new = (char *)malloc(sizeof(char) * new_len);
	if (!new)
		return (0);
	i = 0;
	while (i < new_len - 1)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
