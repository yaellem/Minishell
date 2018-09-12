/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:58:51 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 17:38:13 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**replace(char **nwav, char **nwenv, t_index ind, t_env e)
{
	ind.i = -1;
	while (nwenv[++ind.i])
	{
		e.tmp = ft_strsplit(nwenv[ind.i], '=');
		ind.tmp = ft_strndup(nwav[ind.j], '=');
		if (ft_strcmp(e.tmp[0], ind.tmp) == 0)
		{
			ind.x = 1;
			free(e.nwenv[ind.i]);
			nwenv[ind.i] = ft_strndup(nwav[ind.j], '=');
			e.dst = ft_strinddup(nwav[ind.j], '=');
			nwenv[ind.i] = ft_strjoin(nwenv[ind.i], e.dst);
			ft_strdel(&e.dst);
		}
		free(ind.tmp);
		ft_freetab(e.tmp);
	}
	return (nwenv);
}

char	**check_occurence(char **envcopy, char *nwav, int i)
{
	t_env	e;
	t_index	ind;

	ind.check = 0;
	while (envcopy[++i])
	{
		e.tmp = ft_strsplit(envcopy[i], '=');
		ind.tmp = ft_strndup(nwav, '=');
		if (is_char(nwav, '=') == 0)
		{
			ft_strdel(&ind.tmp);
			ind.tmp = ft_strdup(nwav);
		}
		if (ft_strcmp(e.tmp[0], ind.tmp) == 0)
			envcopy[i] = check_occ_bis(envcopy[i], nwav, &ind.check);
		free(ind.tmp);
		ft_freetab(e.tmp);
	}
	if (ind.check == 0)
	{
		envcopy[i] = is_char(nwav, '=') == 0 ? ft_strjoinnf(nwav, "=''") :
		ft_strdup(nwav);
		envcopy[i + 1] = NULL;
	}
	return (envcopy);
}

int		check_char(char **nwav, char *str)
{
	int		i;
	int		check;

	i = 0;
	check = 1;
	while (nwav[++i])
	{
		if ((str && is_char(nwav[i], '=') == 0) || (nwav[i][0] == '=' &&
			nwav[i][1]))
		{
			check = 0;
			ft_putstr(nwav[i]);
			nwav[i][0] == '=' ? ft_putendl(": Not found") :
			ft_putendl(": There is not the character \'=\'");
			break ;
		}
	}
	return (check);
}

char	**fill_copy(char **envcopy, char **nwav, int i)
{
	int	j;
	int x;

	j = 0;
	x = 0;
	while (nwav[++j])
	{
		x = i;
		i = -1;
		if (ft_strcmp(nwav[j], "=") == 0)
			ft_putendl("setenv: not valid in this context");
		else
			envcopy = check_occurence(envcopy, nwav[j], i);
		i = x;
		i++;
	}
	return (envcopy);
}

char	**set_env(char **nwav, char ***env, char *str)
{
	t_env	e;
	t_index	ind;

	ind.j = 0;
	e.nwenv = *env;
	if ((check_char(nwav, str) == 0) || !nwav[1])
	{
		!nwav[1] ? print_tab_a(*env) : 0;
		return (*env);
	}
	while (nwav[++ind.j])
		e.nwenv = replace(nwav, e.nwenv, ind, e);
	if (!(e.envcopy = malloc(sizeof(char *) * (ft_tablen(e.nwenv) + ind.j))))
		return (NULL);
	ind.i = -1;
	ind.j = 0;
	while (e.nwenv[++ind.i])
		e.envcopy[ind.i] = ft_strdup(e.nwenv[ind.i]);
	e.envcopy[ind.i] = NULL;
	e.envcopy = fill_copy(e.envcopy, nwav, ind.i);
	ft_freetab(*env);
	return (e.envcopy);
}
