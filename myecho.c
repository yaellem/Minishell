/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:39:20 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 18:58:18 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_env(char *str, char **env)
{
	char	**tmp;
	int		i;
	int		check;
	char	*dst;

	i = -1;
	check = 0;
	dst = trim(str);
	while (env[++i])
	{
		tmp = ft_strsplit(env[i], '=');
		if (ft_strcmp(tmp[0], dst) == 0)
			check = 1;
		ft_freetab(tmp);
	}
	if (ft_strcmp(str, "$") == 0)
		check = 1;
	dst ? free(dst) : 0;
	return (check);
}

void	color_end(int opt, char **nwav)
{
	if (opt == 0)
		ft_putchar('\n');
	else if (opt && nwav[2])
	{
		ft_putstr("\x1b[30;47m%");
		ft_putendl("\x1b[0m");
	}
}

int		is_opt(char **nwav, int *opt, int *j)
{
	int	i;

	*opt = 0;
	*j = 0;
	i = 1;
	if (nwav[i] && ft_strcmp(nwav[i], "-n") == 0)
	{
		*opt = 1;
		i++;
	}
	return (i);
}

void	myecho(char **nwav, char **env)
{
	t_index	ind;

	ind.i = is_opt(nwav, &ind.opt, &ind.j);
	while (nwav[ind.i])
	{
		while (nwav[ind.i] && nwav[ind.i][ind.j])
		{
			if (nwav[ind.i][ind.j] == '$' && nwav[ind.i][ind.j + 1])
			{
				if (check_env(&nwav[ind.i][ind.j + 1], env) == 0)
				{
					ind.tmp = trim(&nwav[ind.i][ind.j + 1]);
					ind.j += ft_strlen(ind.tmp) + 1;
					free(ind.tmp);
				}
			}
			ft_putchar(nwav[ind.i][ind.j]);
			ind.j = nwav[ind.i][ind.j] ? ind.j + 1 : ind.j;
		}
		if (nwav[ind.i] && nwav[ind.i + 1])
			ft_putchar(' ');
		ind.j = 0;
		ind.i = nwav[ind.i] ? ind.i + 1 : ind.i;
	}
	color_end(ind.opt, nwav);
}
