/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:07:05 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/21 00:18:04 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char *line, char **nwenv)
{	
	t_env	e;
	t_index	ind;

	ind.x = 0;
	ind.i = 0;
	e.nwav = NULL;
	e.str = NULL;
	if (line[0] != '\0')
		    e.nwav = virgule_point(line);
	while (e.nwav != NULL  && e.nwav[ind.x])
	{
		while (e.nwav[ind.x][ind.i])
		{
			e.nwav[ind.x][ind.i] = dollar(e.nwav[ind.x][ind.i], nwenv);
			ind.i++;
		}
		if ((builtin_gestion(e.nwav[ind.x], &nwenv)) == -1)
			binary_gestion(e.nwav[ind.x], nwenv, e.str);
		ft_freetab(e.nwav[ind.x]);
		ind.i = 0;
		ind.x++;
	}
}
