/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:56:54 by ski               #+#    #+#             */
/*   Updated: 2021/11/15 14:57:02 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
static int	sk_isset(char c, const char *set);

/* ************************************************************************** */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;
	size_t	new_len;
	char	*new;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	while ((sk_isset(s1[i], set)) & (s1[i] != '\0'))
		i++;
	s1_len--;
	while ((sk_isset(s1[s1_len], set)) & (s1_len > i))
		s1_len--;
	new_len = s1_len - i + 1;
	new = ft_calloc(new_len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memmove(new, s1 + i, new_len);
	new[new_len] = '\0';
	return (new);
}

/* ************************************************************************** */
static int	sk_isset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/* char	*ft_strtrim(char const *s1, char const *set)
{
	size_t s1_len;
	size_t i;
	char *new;
	

	if (!s1)
		return (NULL);

	s1_len = ft_strlen(s1) - 1;

	while (sk_isset(s1[s1_len], set))
		s1_len--;

	s1_len++;

	s1[s1_len] = '\0';

	while ( sk_isset( s1[0], set))
		{
			ft_memmove((void *)s1, (void *)s1 + 1, s1_len);
			s1_len--;
		}

	new = (char *)malloc(s1_len * sizeof(char));
	if (!new)
		return (NULL);

	ft_memmove((void *)new, (void *)s1, s1_len + 1);

	return (new);
} */