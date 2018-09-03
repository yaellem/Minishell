/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:39:20 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/03 23:13:05 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_env(char	*str, char **env)
{
	char	**tmp;
	int		i;
	int		check;
	char	*dst;

	i = -1;
	check = 0;
	dst = trim(str);
	//ft_putendl(str);
	//str = trim(str);
	while (env[++i])
	{
		tmp = ft_strsplit(env[i], '=');
		if (ft_strcmp(tmp[0], dst) == 0)
			check = 1;
		ft_freetab(tmp);
	}
	if (ft_strcmp(str, "$") == 0)
		check = 1;
	return (check);
}

void	myecho(char **nwav, char **env)
{
	int	i;
	int	j;
	int	opt;
	char *tmp;

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
			if (nwav[i][j] == '$' && nwav[i][j+ 1])
			{
				if (check_env(&nwav[i][j + 1], env) == 0)
				{
					tmp = trim(&nwav[i][j + 1]);
					/*ft_putstr(">   ");
					ft_putstr(tmp);	
					ft_putendl("    <");*/
					 j += ft_strlen(tmp) + 1;
					 free(tmp);
					//i++;
				}
			}
			ft_putchar(nwav[i][j]);
			j = nwav[i][j] ? j + 1 : j;;
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
