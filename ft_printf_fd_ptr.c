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
static size_t	sk_puthex_recursive(unsigned long n, int fd);
static char		conv_dec_to_hex(unsigned int u_number);

/* ************************************************************************** */
size_t	ft_printf_fd_ptr(unsigned long u_number, int fd)
{
	size_t	cnt_prnt;

	cnt_prnt = 0;
	write(fd, "0x", 2);
	cnt_prnt += 2;
	cnt_prnt += sk_puthex_recursive(u_number, fd);
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned long ul_number, int fd)
{
	char	c;
	size_t	cnt_prnt;

	cnt_prnt = 0;
	if ((0 <= ul_number) && (ul_number <= 15))
	{
		c = conv_dec_to_hex(ul_number);
		write(fd, &c, 1);
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_puthex_recursive((ul_number / 16), fd);
		ul_number = ul_number % 16;
		c = conv_dec_to_hex(ul_number);
		write(fd, &c, 1);
		cnt_prnt++;
	}
	return (cnt_prnt);
}

/* ************************************************************************** */
static char	conv_dec_to_hex(unsigned int u_number)
{
	char	c;

	if (u_number < 10)
		c = u_number + '0';
	else
		c = u_number - 10 + 'a';
	return (c);
}
