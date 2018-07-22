/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:43:00 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/22 04:30:09 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	//	int		i;
	int		j;
	char	**tab;

	j = 0;
	if (!(tab = malloc(sizeof(char *) * (ft_countnum(s, c) + 1))))
		return (NULL);
	/*	while (*s)
		{
		while (*s && *s == c)
		s++;
		if (!(*s))
		break ;
		i = 0;
		while (*s && *s != c)
		{
		if (*s == '"')
		{
		while (*s && *s != '"')
		i++;
		break ;
		}
		i++;
		s++;
		}
		return (NULL);
		j++;
		}*/
	return (tab);
}

char			**ft_strsplitq(char const *s, char c)
{
	int		i;
	int		j;
	int		x;
	char	**tab;

	tab = ft_malloc(s, c);
	j = 0;
	x = 0;
	while (s[x])
	{
		i = 0;
		while (s[x] && s[x] == c)
			x++;
		tab[j] = malloc(sizeof(char) * (ft_strlen(s) + 1));
		while (s[x] && s[x] != c)
		{
			if (s[x] == '\'')
			{
				tab[j][i++] = s[x++];
				//ft_putchar(tab[j][i]);
				//x++;
				while (s[x] && s[x] != '\'')
				{
					tab[j][i++] = s[x];
					x++;
				}
				tab[j][i++] = s[x++];
				//x++;
				break ;
			}
			if (s[x] == '"')
			{
				tab[j][i++] = s[x++];
				//ft_putchar(tab[j][i]);
				//x++;
				while (s[x] && s[x] != '"')
				{
					tab[j][i++] = s[x];
					x++;
				}
				tab[j][i++] = s[x++];
				//x++;
				break ;
			}
			else 
			{
				tab[j][i++] = s[x];
				x++;
			}
		}
		tab[j][i] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
