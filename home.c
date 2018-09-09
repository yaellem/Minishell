/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:33:36 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 02:47:38 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_occ_bis(char *envcopy, char *nwav, int *check)
{
	t_env	e;

	if (is_char(nwav, '='))
	{
		free(envcopy);
		envcopy = ft_strndup(nwav, '=');
		e.str = ft_strinddup(nwav, '=');
		envcopy = ft_strjoin(envcopy, e.str);
		free(e.str);
		ft_putendl("LOL");
	}
	*check = 1;
	return (envcopy);
}

char	*tilde(char **envp)
{
	int		i;
	char	*tilde;
	char	**tmp;

	i = 0;
	tilde = NULL;
	while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0], "HOME") == 0)
		{
			tilde = ft_strdup(tmp[1]);
			ft_freetab(tmp);
			break ;
		}
		ft_freetab(tmp);
		i++;
	}
	return (tilde);
}

char	*tiret(char **envp)
{
	int		i;
	char	*tiret;
	char	**tmp;

	i = 0;
	tiret = NULL;
	while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0], "OLDPWD") == 0)
		{
			tiret = ft_strdup(tmp[1]);
			ft_freetab(tmp);
			break ;
		}
		ft_freetab(tmp);
		i++;
	}
	return (tiret);
}
