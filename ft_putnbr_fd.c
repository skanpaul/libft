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
static size_t	ft_putnbr_fd_recursive(long l_number, int fd);

/* ************************************************************************** */
// RETURN 0 IF THERE IS AN ERROR WHEN:
//		fd == -1
//		write() return -1
/* ************************************************************************** */
size_t	ft_putnbr_fd(int number, int fd)
{
	long	l_number;
	size_t	cnt_print;

	if (fd == -1)
		return (0);

	cnt_print = 0;
	l_number = (long)number;

	if (l_number < 0)
	{
		l_number *= (-1);
		if(write(fd, "-", 1) == -1)
			return(0);
		cnt_print++;
	}

	cnt_print += ft_putnbr_fd_recursive(l_number, fd);
	return (cnt_print);
}

/* ************************************************************************** */
static size_t	ft_putnbr_fd_recursive(long l_number, int fd)
{
	char	c;
	size_t cnt_print;

	cnt_print = 0;

	if ((0 <= l_number) & (l_number <= 9))
	{
		c = l_number + '0';
		if(write(fd, &c, 1) == -1)
			return (0);
		cnt_print++;
	}
	else
	{
		cnt_print += ft_putnbr_fd_recursive((l_number / 10), fd);
		c = (l_number % 10) + '0';
		if (write(fd, &c, 1) == -1)
			return (0);
		cnt_print++;
	}
	return(cnt_print);
}
