/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:35:36 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 01:28:31 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	if (!(s1))
		return (NULL);
	if ((!(s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1)))))
		return (0);
	while (s1[i])
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[i] = '\0';
	return (s2);
}
