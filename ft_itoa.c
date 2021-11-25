/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:41:22 by ski               #+#    #+#             */
/*   Updated: 2021/11/19 10:41:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
char	*sk_itoa_recursiv(long value, int neg, size_t *str_len, size_t *i);

/* ************************************************************************** */
char	*ft_itoa(int n)
{
	long	n_long;
	int		neg;
	char	*str;
	size_t	str_len;
	size_t	i;

	n_long = (long)n;
	neg = 0;
	str_len = 1;
	i = 0;
	if (n_long < 0)
	{
		n_long *= (-1);
		neg = 1;
		str_len++;
	}
	str = sk_itoa_recursiv(n_long, neg, &str_len, &i);
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	return (str);
}

/* ************************************************************************** */
char	*sk_itoa_recursiv(long value, int neg, size_t *str_len, size_t *i)
{
	char	*str;

	str = NULL;
	if ((0 <= value) & (value <= 9))
	{
		str = (char *) malloc((*str_len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		if (neg == 1)
		{
			str[*i] = '-';
			(*i)++;
		}
	}
	else
	{
		*str_len += 1;
		str = sk_itoa_recursiv((value / 10), neg, str_len, i);
		if (!str)
			return (NULL);
	}
	str[*i] = (value % 10) + '0';
	(*i)++;
	return (str);
}
