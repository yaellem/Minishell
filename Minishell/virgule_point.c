/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virgule_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:26:43 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/22 04:34:38 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***virgule_point(char *line)
{
	char	**tmp;
	char	***nwav;
	int		y;
	int 	i;
	int		quote;

	y = 0;
	i = 0;
	quote = 0;
	while (line[i])
	{
		if (line[i] == '"')
			quote = 1;
		if (line[i])
			y++;
		i++;
	}
	nwav = malloc(sizeof(char**) * (y + 1));
	if (y == 0)
	{
			nwav[0] = ft_strsplit(line, ' ');
		return (nwav);
	}
	i = 0;
	y = 0;
	tmp = ft_strsplit(line, ';');
	while (tmp[i])
	{
		nwav[y] = ft_strsplit(tmp[i], ' ');
		//nwav[y] = ft_strsplitq(tmp[i], ' ');
		y++;
		i++;
	}
	nwav[y] = NULL;
	return (nwav);
}
