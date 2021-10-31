/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:53:03 by ski               #+#    #+#             */
/*   Updated: 2021/10/29 14:53:07 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
int	ft_isprint(int c)
{
	if (((040 <= c) & (c <= 047)) |
		((050 <= c) & (c <= 057)) |
		((060 <= c) & (c <= 067)) |
		((070 <= c) & (c <= 077) )|
		((0100 <= c) & (c <= 0107)) |
		((0110 <= c) & (c <= 0117)) |
		((0120 <= c) & (c <= 0127)) |
		((0130 <= c) & (c <= 0137)) |
		((0140 <= c) & (c <= 0147)) |
		((0150 <= c) & (c <= 0157)) |
		((0160 <= c) & (c <= 0167)) |
		((0170 <= c) & (c <= 0176)))
		return (1);
	return (0);
}
