/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:02:03 by ski               #+#    #+#             */
/*   Updated: 2021/12/02 14:02:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
static size_t	sk_recursive(unsigned long n_long, int fd, size_t cnt_prnt);

/* ************************************************************************** */
size_t	ft_putnbr_fd_u(unsigned int n, int fd)
{
	unsigned long	n_ul;
	size_t			cnt_prnt;

	cnt_prnt = 0;
	if (fd == -1)
		return (0);
	n_ul = (unsigned long)n;
	cnt_prnt += sk_recursive(n_ul, fd, cnt_prnt);
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_recursive(unsigned long n_ul, int fd, size_t cnt_prnt)
{
	char	c;

	if ((0 <= n_ul) & (n_ul <= 9))
	{
		c = n_ul + '0';
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_recursive((n_ul / 10), fd, cnt_prnt);
		c = (n_ul % 10) + '0';
		cnt_prnt++;
	}
	write(fd, &c, 1);
	return (cnt_prnt);
}
