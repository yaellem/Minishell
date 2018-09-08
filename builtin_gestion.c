/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 00:15:26 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/06 00:10:33 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_gestion(char **nwav, char ***env)
{
	if (!env || !*env)
	{
		ft_putendl("We need an environnement, sorry!");
		return (-1);
	}
	if (nwav[0] && (ft_strcmp(nwav[0], "echo")) == 0)
		myecho(nwav, *env);
	else if (nwav[0] && (ft_strcmp(nwav[0], "cd")) == 0)
		ch_dir(nwav[1], env);
	else if (nwav[0] && (ft_strcmp(nwav[0], "exit")) == 0)
		nwav[1] ? exit(ft_atoi(nwav[1])) : exit(0);
	else if (nwav[0] && (ft_strcmp(nwav[0], "setenv")) == 0)
		*env = set_env(nwav, env, NULL);
	else if (nwav[0] && (ft_strcmp(nwav[0], "unsetenv")) == 0)
		*env = unset_env(nwav, env);
	else if (nwav[0] && (ft_strcmp(nwav[0], "env")) == 0)
		*env = envi(env, nwav);
	else if (nwav[0] && (ft_strcmp(nwav[0], "pwd")) == 0)
		pwd(nwav);
	else
		return (-1);
	return (0);
}
