/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:13:14 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/24 03:13:17 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_f)
{
	int	i;
	int	y;
	int m;

	i = 0;
	if (to_f[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		y = 0;
		if (str[i] == to_f[y])
		{
			m = i;
			while (str[i] == to_f[y])
			{
				if (to_f[y + 1] == '\0')
					return ((char *)str + i - y);
				i++;
				y++;
			}
			i = m;
		}
		i++;
	}
	return (0);
}
