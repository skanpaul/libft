/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:09:38 by ski               #+#    #+#             */
/*   Updated: 2021/12/02 11:09:42 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned long n, int fd, size_t cnt_prnt);

/* ************************************************************************** */
size_t	sk_putptr_fd(unsigned long n, int fd)
{
	size_t	cnt_prnt;
	char	c;

	cnt_prnt = 0;
	c = '\0';
	write(fd, "0x", 2);
	cnt_prnt = sk_puthex_recursive(n, fd, cnt_prnt) + 2;
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned long n, int fd, size_t cnt_prnt)
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
