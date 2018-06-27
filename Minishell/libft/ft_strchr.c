/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:50:47 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/17 07:36:19 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;
	int		i;
	char	*y;

	x = (char)c;
	i = 0;
	y = (char *)s;
	if (x == '\0')
	{
		while (y[i] - 1)
		{
			if (y[i] == x)
				return (y + i);
			i++;
		}
	}
	if (*s == 0)
		return ((char *)0);
	while (y[i])
	{
		if (y[i] == x)
			return (y + i);
		i++;
	}
	return (NULL);
}
