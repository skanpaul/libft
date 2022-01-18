/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:33:36 by ski               #+#    #+#             */
/*   Updated: 2021/11/21 09:33:39 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
static size_t	sk_putnbr_recursive(long n_long, int fd);

/* ************************************************************************** */
size_t	sk_putnbr_fd(int n, int fd)
{
	long	n_long;
	size_t	cnt_prnt;

	if (fd == -1)
		return (0);
	cnt_prnt = 0;
	n_long = (long)n;
	if (n_long < 0)
	{
		n_long *= (-1);
		write(fd, "-", 1);
		cnt_prnt++;
	}
	cnt_prnt += sk_putnbr_recursive(n_long, fd);
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_putnbr_recursive(long n_long, int fd)
{
	char	c;
	size_t	cnt_prnt;

	cnt_prnt = 0;
	if ((0 <= n_long) & (n_long <= 9))
	{
		c = n_long + '0';
		write(fd, &c, 1);
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_putnbr_recursive((n_long / 10), fd);
		c = (n_long % 10) + '0';
		write(fd, &c, 1);
		cnt_prnt++;
	}
	return (cnt_prnt);
}
