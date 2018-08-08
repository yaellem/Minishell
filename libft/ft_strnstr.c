/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 06:19:47 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/24 03:20:33 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_f, size_t len)
{
	size_t i;
	size_t y;
	size_t m;

	i = 0;
	if (to_f[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (0);
	while (str[i] != '\0' && i < len)
	{
		y = 0;
		if (str[i] == to_f[y])
		{
			m = i;
			while (str[i] == to_f[y++] && i < len)
				if (to_f[y] == '\0')
					return ((char *)str + i - (y - 1));
				else
					i++;
			i = m;
		}
		i++;
	}
	return (0);
}
