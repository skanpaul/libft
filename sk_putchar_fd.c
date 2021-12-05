/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:11:57 by ski               #+#    #+#             */
/*   Updated: 2021/11/21 09:12:11 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
size_t	sk_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return (0);
	write(fd, &c, 1);
	return (1);
}