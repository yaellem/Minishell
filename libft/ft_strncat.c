/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:45:44 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/15 00:24:03 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t y;

	i = 0;
	y = ft_strlen((const char *)s1);
	while (s2[i] && i < n)
	{
		s1[y] = s2[i];
		y++;
		i++;
	}
	s1[y] = '\0';
	return (s1);
}
