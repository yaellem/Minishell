/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:43:00 by ymarcill          #+#    #+#             */
/*   Updated: 2018/05/15 04:00:12 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countnum(char const *s, char c)
{
	int		x;

	x = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		while (*s && *s != c)
			s++;
		x = x + 1;
	}
	return (x);
}

static char		**ft_malloc(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	if (!(tab = malloc(sizeof(char *) * (ft_countnum(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		i = 0;
		while (*s && *s != c)
		{
			i++;
			s++;
		}
		if (!(tab[j] = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		j++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!(tab = ft_malloc(s, c)))
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		i = 0;
		while (*s && *s != c)
		{
			tab[j][i++] = *s;
			s++;
		}
		tab[j][i] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
