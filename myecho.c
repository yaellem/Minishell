/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:39:20 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/31 23:23:24 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_env(char	*str, char **env)
{
	char	**tmp;
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (env[++i])
	{
		tmp = ft_strsplit(env[i], '=');
		if (ft_strcmp(tmp[0], &str[1]) == 0)
			check = 1;
		ft_freetab(tmp);
	}
	if (str[0] != '$')
		check = 1;
	return (check);
}

void	myecho(char **nwav, char **env)
{
	int	i;
	int	j;
	int	opt;

	i = 1;
	j = 0;
	opt = 0;
//	(void)env;
	if (nwav[i] && ft_strcmp(nwav[i], "-n") == 0)
	{
		opt = 1;
		i++;
	}
	while (nwav[i])
	{
		while (nwav[i] && nwav[i][j])
		{
			if (nwav[i][j] == '$')
			{
				if (check_env(&nwav[i][j], env) == 0)
				{
					break ;
					i++;
					}
			}
			ft_putchar(nwav[i][j]);
			j++;
		}
		if (nwav[i] && nwav[i + 1])
			ft_putchar(' ');
		j = 0;
		i = nwav[i] ? i + 1 : i;
	}
	if (opt == 0)
		ft_putchar('\n');
	else if (opt && nwav[2])
	{
		ft_putstr("\x1b[30;47m%");
		ft_putendl("\x1b[0m");
	}
}
