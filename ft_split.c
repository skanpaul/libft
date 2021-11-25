/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:30:39 by ski               #+#    #+#             */
/*   Updated: 2021/11/16 13:30:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
static int		sk_ischar(char c_in, char c_cmp);
static size_t	sk_cnt_word(const char *s, char delimiter_c);
static void		sk_fill_word_list(const char *s, char **word_list, char c);

/* ************************************************************************** */
char	**ft_split(char const *s, char c)
{
	size_t	w;
	char	**str_array;
	char	*new;
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	new = ft_strtrim(s, set);
	if (!new)
		return (NULL);
	w = sk_cnt_word(new, c);
	str_array = (char **)malloc((w + 1) * sizeof(char *));
	if (!str_array)
	{
		free(new);
		return (NULL);
	}
	str_array[w] = NULL;
	sk_fill_word_list(new, str_array, c);
	free(new);
	return (str_array);
}

/* ************************************************************************** */
static int	sk_ischar(char c_in, char c_cmp)
{
	if (c_in == c_cmp)
		return (1);
	return (0);
}

/* ************************************************************************** */
static size_t	sk_cnt_word(const char *s, char delimiter_c)
{
	size_t	w;
	size_t	i;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((!sk_ischar(s[i], delimiter_c))
			& ((sk_ischar(s[i + 1], delimiter_c)) | (!s[i + 1])))
			w++;
		i++;
	}
	return (w);
}

/* ************************************************************************** */
static void	sk_fill_word_list(const char *s, char **word_list, char c)
{
	size_t	w;
	size_t	i_old;
	size_t	i;

	w = 0;
	i_old = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((!sk_ischar(s[i], c))
			& ((sk_ischar(s[i + 1], c)) | (!s[i + 1])))
		{
			word_list[w] = ft_substr(s, i_old, (i - i_old + 1));
			w++;
		}
		if ((sk_ischar(s[i], c)) & (!sk_ischar(s[i + 1], c)))
			i_old = i + 1;
		i++;
	}
}

/* ************************************************************************** */
// char	**ft_split(char const *s, char c)
// {
// 	size_t	w;
// 	size_t	w_len;
// 	size_t	i;
// 	size_t	i_old;
// 	char	**str_array;
// 	char	*new;
// 	char	set[2];

// 	set[0] = c;
// 	set[1] = '\0';
// 	/* -------------------------------------- */
// 	new = ft_strtrim(s, set);
// 	if (!new)
// 		return (NULL);
// 	/* -------------------------------------- */
// 	w = 0;
// 	i = 0;
// 	while (new[i] != '\0')
// 	{
// 		if ((!sk_ischar(new[i], c))
// 			& ((sk_ischar(new[i + 1], c)) | (!new[i + 1])))
// 			w++;
// 		i++;
// 	}
// 	/* -------------------------------------- */
// 	str_array = (char **)malloc((w + 1) * sizeof(char *));
// 	if (!str_array)
// 	{
// 		free(new);
// 		return (NULL);
// 	}
// 	str_array[w] = NULL;
// 	/* -------------------------------------- */
// 	w = 0;
// 	i_old = 0;
// 	i = 0;
// 	while (new[i] != '\0')
// 	{
// 		if ((!sk_ischar(new[i], c))
// 			& ((sk_ischar(new[i + 1], c)) | (!new[i + 1])))
// 		{
// 			w_len = i - i_old + 1;
// 			str_array[w] = ft_substr(new, i_old, w_len);
// 			w++;
// 		}
// 		if ((sk_ischar(new[i], c)) & (!sk_ischar(new[i + 1], c)))
// 			i_old = i + 1;
// 		i++;
// 	}
// 	/* -------------------------------------- */
// 	free(new);
// 	return (str_array);
// }