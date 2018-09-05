/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:33:36 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/05 20:34:20 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
