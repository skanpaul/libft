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
#include "libft.h"

/* ************************************************************************** */
static size_t	sk_putnbr_recursive(long n_long, int fd, size_t cnt_prnt);

/* ************************************************************************** */
size_t	sk_putnbr_s_fd(int n, int fd)
{
	long	n_long;
	size_t	cnt_prnt;
	int		neg;

	neg = 0;
	cnt_prnt = 0;
	if (fd == -1)
		return (0);
	n_long = (long)n;
	if (n_long < 0)
	{
		n_long *= (-1);
		write(fd, "-", 1);
		neg = 1;
	}
	cnt_prnt += sk_putnbr_recursive(n_long, fd, cnt_prnt);
	if (neg == 1)
		cnt_prnt++;
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_putnbr_recursive(long n_long, int fd, size_t cnt_prnt)
{
	char	c;

	if ((0 <= n_long) & (n_long <= 9))
	{
		c = n_long + '0';
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_putnbr_recursive((n_long / 10), fd, cnt_prnt);
		c = (n_long % 10) + '0';
		cnt_prnt++;
	}
	write(fd, &c, 1);
	return (cnt_prnt);
}
