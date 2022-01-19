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
static size_t	sk_recursive(unsigned long n_long, int fd);

/* ************************************************************************** */
size_t	ft_putnbr_fd_u(unsigned int u_number, int fd)
{
	unsigned long	ul_number;
	size_t			cnt_prnt;

	if (fd == -1)
		return (0);
	cnt_prnt = 0;
	ul_number = (unsigned long)u_number;
	cnt_prnt += sk_recursive(ul_number, fd);
	return (cnt_prnt);
}

/* ************************************************************************** */
static size_t	sk_recursive(unsigned long ul_number, int fd)
{
	char	c;
	size_t	cnt_prnt;

	cnt_prnt = 0;
	if ((0 <= ul_number) & (ul_number <= 9))
	{
		c = ul_number + '0';
		write(fd, &c, 1);
		cnt_prnt++;
	}
	else
	{
		cnt_prnt += sk_recursive((ul_number / 10), fd);
		c = (ul_number % 10) + '0';
		write(fd, &c, 1);
		cnt_prnt++;
	}
	return (cnt_prnt);
}
