/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_puthex_up_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:33:27 by ski               #+#    #+#             */
/*   Updated: 2021/12/02 16:33:31 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned int n, int fd);
static char		conv_dec_to_hex(unsigned int u_number);
/* ************************************************************************** */
size_t	ft_printf_fd_xup(int number, int fd)
{
	size_t			cnt_prnt;
	unsigned int	u_number;

	u_number = (unsigned long)number;
	cnt_prnt = 0;
	cnt_prnt += sk_puthex_recursive(u_number, fd);
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_puthex_recursive(unsigned int u_number, int fd)
{
	char			c;
	size_t 			cnt_prnt;

	cnt_prnt = 0;
	if ((0 <= u_number) && (u_number <= 15))
	{
		c = conv_dec_to_hex(u_number);
		write(fd, &c, 1);
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_puthex_recursive((u_number / 16), fd);
		u_number = u_number % 16;
		c = conv_dec_to_hex(u_number);
		write(fd, &c, 1);
		cnt_prnt++;
	}
	return (cnt_prnt);
}

/* ************************************************************************** */
static char	conv_dec_to_hex(unsigned int u_number)
{
	char c;
	
	if (u_number < 10)
		c = u_number + '0';
	else
		c = u_number - 10 + 'A';
	return (c);
}