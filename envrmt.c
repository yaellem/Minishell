/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envrmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:55:56 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/06 00:25:38 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**envrmt(char **envp)
{
	t_env	e;
	int		i;
	int		x;

	i = -1;
	e.str = NULL;
	e.nwenv = (char**)malloc(sizeof(char*) * (ft_tablen(envp) + 1));
	while (envp[++i])
	{
		e.tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(e.tmp[0], "SHLVL") == 0)
		{
			x = ft_atoi(e.tmp[1]) + 1;
			e.str = ft_itoa(x);
			e.nwenv[i] = ft_strjoinnf("SHLVL=", e.str);
			free(e.str);
		}
		else
			e.nwenv[i] = ft_strdup(envp[i]);
		ft_freetab(e.tmp);
	}
	e.nwenv[i] = NULL;
	return (e.nwenv);
}
