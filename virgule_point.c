/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virgule_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:26:43 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 02:00:03 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check(char *line)
{
	int i;
	int	y;

	i = 0;
	y = 0;
	while (line[i])
	{
		if (line[i])
			y++;
		i++;
	}
	return (y);
}

char	***virgule_point(char *line)
{
	char	**tmp;
	char	***nwav;
	int		y;
	int		i;

	y = check(line);
	i = 0;
	nwav = malloc(sizeof(char**) * (y + 1));
	if (y == 0)
	{
		nwav[0] = ft_strsplit(line, ' ');
		return (nwav);
	}
	y = 0;
	tmp = ft_strsplit(line, ';');
	while (tmp[i])
	{
		nwav[y] = ft_strsplit(tmp[i], ' ');
		y++;
		i++;
	}
	ft_freetab(tmp);
	nwav[y] = NULL;
	return (nwav);
}
