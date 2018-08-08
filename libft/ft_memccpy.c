/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:04:06 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/17 02:08:15 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*x;
	unsigned char		*y;
	unsigned char		j;

	i = 0;
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	j = (unsigned char)c;
	while (i < n)
	{
		x[i] = y[i];
		if (y[i] == j)
			return (x + i + 1);
		i++;
	}
	return ((void *)0);
}
