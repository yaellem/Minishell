/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:07:05 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 18:57:31 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*minishell_core_bis(char *nwav, char **nwenv)
{
	char	*tmp;

	if (nwav && nwav[0] == '~' && nwav[1] == '/')
	{
		tmp = ft_strdup(nwav);
		free(nwav);
		nwav = tilde(nwenv);
		if (tmp[2])
			nwav = ft_strjoin(nwav, ft_strchr(tmp, '/'));
		else
			nwav = ft_strjoin(nwav, "/");
		free(tmp);
	}
	return (nwav);
}

char	**minishell_core(char **nwav, char **nwenv)
{
	t_env	e;
	t_index	ind;

	ind.i = -1;
	while (nwav[++ind.i])
	{
		e.dst = nwav[ind.i];
		nwav[ind.i] = dollar(e.dst, nwenv);
		free(e.dst);
		if (nwav[ind.i] && nwav[ind.i][0] == '~' && !nwav[ind.i][1])
		{
			free(nwav[ind.i]);
			nwav[ind.i] = tilde(nwenv);
		}
		nwav[ind.i] = minishell_core_bis(nwav[ind.i], nwenv);
		if (nwav[ind.i] && nwav[ind.i][0] == '~' && nwav[ind.i][1] && nwav
		[ind.i][1] != '/' && nwav[ind.i][1] != '~' && nwav[ind.i][2])
		{
			ft_putstr("minishell: no such user or named directory: ");
			ft_putendl(&nwav[ind.i][1]);
		}
	}
	return (nwav);
}
