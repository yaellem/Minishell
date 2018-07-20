/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 01:58:59 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/19 23:10:25 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		unset_nb_arg_error(char **name)
{
	if (!name[1])
	{
		ft_putendl("Not enough arguments");
		return (-1);
	}
	if (name[2])
	{
		ft_putendl("Too many arguments");
		return (-1);
	}
	return (0);
}

int		unset_bad_arg(char **name, char **nwenv)
{
	int		i;
	int		check;
	char	**tmp;

	i = 0;
	check = 0;
	while (nwenv[i])
	{
		tmp = ft_strsplit(nwenv[i], '=');
		if ((ft_strcmp(tmp[0], name[1])) == 0)
			check = 1;
		ft_freetab(tmp);
		i++;
	}
	if (check == 0)
	{
		ft_putstr("The environment variable \"");
		ft_putstr(name[1]);
		ft_putendl("\" does not exist");
		return (-1);
	}
	return (i);
}

char	**unset_copy(char **name, char **nwenv)
{
	char	**tmp;
	char	**envcopy;
	t_index	ind;

	ind.i = 0;
	ind.y = 0;
	if (!(envcopy = malloc(sizeof(char *) * (unset_bad_arg(name, nwenv) + 1))))
		return (NULL);
	while (nwenv[ind.i])
	{
		tmp = ft_strsplit(nwenv[ind.i], '=');
		if ((ft_strcmp(tmp[0], name[1])) != 0)
		{
			ft_putendl(tmp[0]);
			envcopy[ind.y++] = ft_strdup(nwenv[ind.i]);
		}
		ft_freetab(tmp);
		ind.i++;
	}
	envcopy[ind.y] = NULL;
	return (envcopy);
}

char	**unset_env(char **name, char ***env)
{
	t_env	e;
	char	**envcopy;

	e.nwenv = *env;
	if (unset_nb_arg_error(name) == -1 || unset_bad_arg(name, e.nwenv) == -1)
		return (NULL);
	envcopy = unset_copy(name, e.nwenv);
	return (envcopy);
}
