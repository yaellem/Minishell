/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 04:51:10 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/17 07:14:44 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*s1;
	size_t		i;
	char		c1;

	s1 = (char *)s;
	c1 = (char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void*)(s1 + i));
		++i;
	}
	return (NULL);
}
