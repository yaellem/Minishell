/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:28:37 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/16 18:51:00 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*x;
	unsigned const char *y;

	i = 0;
	x = (unsigned char *)dst;
	y = (unsigned const char *)src;
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
