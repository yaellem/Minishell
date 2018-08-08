/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:27:13 by ymarcill          #+#    #+#             */
/*   Updated: 2018/01/23 21:18:04 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, char c)
{
	int		i;
	int		n;
	char	*s2;

	i = 0;
	n = 0;
	while (s1[i])
	{
		if (s1[i] == c)
		{
			n = i;
			break ;
		}
		i++;
	}
	if ((!(s2 = malloc(sizeof(char) * (i + 1)))))
		return (0);
	i = -1;
	if (c == '\0')
		n = ft_strlen(s1) + 1;
	while (++i < n)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
