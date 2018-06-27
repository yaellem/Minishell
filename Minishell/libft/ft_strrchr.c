/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:39:38 by ymarcill          #+#    #+#             */
/*   Updated: 2018/03/12 16:46:40 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
	i = ft_strlen(y);
	while (i >= 0)
	{
		if (y[i] == x)
			return (y + 1 + i);
		i--;
	}
	return (NULL);
}
