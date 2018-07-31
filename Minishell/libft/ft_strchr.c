/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:50:47 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/31 22:44:33 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char	x;
	int		i;

	x = (char)c;
	i = 0;
	if (x == '\0')
	{
		while (s[i] - 1)
		{
			if (s[i] == x)
				return (s + i);
			i++;
		}
	}
	if (*s == 0)
		return ((char *)0);
	while (s[i])
	{
		if (s[i] == x)
			return (s + i);
		i++;
	}
	return (NULL);
}
