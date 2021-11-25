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
void	sk_putnbr_recursive(long n_long, int fd);

/* ************************************************************************** */
void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	if (fd == -1)
		return ;
	n_long = (long)n;
	if (n_long < 0)
	{
		n_long *= (-1);
		write(fd, "-", 1);
	}
	sk_putnbr_recursive(n_long, fd);
}

/* ************************************************************************** */
void	sk_putnbr_recursive(long n_long, int fd)
{
	char	c;

	if ((0 <= n_long) & (n_long <= 9))
	{
		c = n_long + '0';
	}
	else
	{
		sk_putnbr_recursive((n_long / 10), fd);
		c = (n_long % 10) + '0';
	}
	write(fd, &c, 1);
}
