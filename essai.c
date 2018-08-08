/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 02:07:03 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/18 20:30:08 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trim_quote(char ***nwav)
{
	char	**dst;
	char	*line;
	int		dquote;
	int		quote;
	int 	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	dquote = 0;
	quote = 0;
	dst = *nwav;
	while (dst[i])
	{
		while (dst[i][j])
		{
			if (dst[i][j] == '\"' || dst[i][j] == '\'')
			{
				if (dst[i][j] == '\"')
					dquote++;
				else
					quote++;
				j++;
			}
			dst[i][k++]= dst[i][j++];
		}
		dst[i][k] = '\0';
		j = 0;
		k = 0;
		i++;
	}
	dst[i] = NULL;
	print_tab_a(dst);
	if ((dquote % 2) != 0)
	{
		ft_putstr("dquote>");
		while (get_next_line(0, &line))
		{
			dst = malloc(sizeof(char*) * (i + 2));
			if (ft_is_here(line, '\"') == 0)
			{
				dst[i++] = ft_strndup(line, '\"');
				break;
			}
			dst[i++] = ft_strdup(line);
			ft_putstr("dquote>");
		}
		dst[i] = NULL;
		print_tab_a(dst);
	}
/*	else if ((quote % 2) != 0)
	{
		while (get_next_line(0, &line))
		{
			ft_putstr("dquote>");
			while (line[i] && line[i] != '\'')
			{
				if (line[i] == '\"')
				{
					dst[y] = NULL;
					break;
				}
				dst = malloc(sizeof(char*) * (y + 2));
				dst[y][z++] = line[i];
				i++;

			}
			y++;
			if (line[i] == '\'')
			{
				dst[y] = NULL;
				break;
			}
		}
	}*/
}
