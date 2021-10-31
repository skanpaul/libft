/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:04 by ski               #+#    #+#             */
/*   Updated: 2021/10/28 14:11:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __LIBFT_H__
# define __LIBFT_H__
#include "libft.h"
#endif
/* ************************************************************************** */

#include <stdio.h>
/*****************************/

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
