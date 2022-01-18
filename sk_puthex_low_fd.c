/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:47:04 by ski               #+#    #+#             */
/*   Updated: 2021/12/02 14:47:06 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned int n, int fd, size_t cnt_prnt);

/* ************************************************************************** */
size_t	sk_puthex_low_fd(int n, int fd)
{
	size_t			cnt_prnt;
	unsigned int	n_u;

	n_u = (unsigned long)n;
	cnt_prnt = 0;
	return (sk_puthex_recursive(n_u, fd, cnt_prnt));
}

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned int n, int fd, size_t cnt_prnt)
{
	char			c;
	unsigned long	modulo;

	if ((0 <= n) && (n <= 15))
	{
		if (n < 10)
			c = n + '0';
		else
			c = n - 10 + 'a';
		write(fd, &c, 1);
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_puthex_recursive((n / 16), fd, cnt_prnt);
		modulo = n % 16;
		if (modulo < 10)
			c = modulo + '0';
		else
			c = modulo - 10 + 'a';
		write(fd, &c, 1);
		cnt_prnt++;
	}
	return (cnt_prnt);
}
