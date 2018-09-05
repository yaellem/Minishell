/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:53:19 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/05 19:54:25 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**envi(char ***envp, char **nwav)
{
	int		i;
	int		x;
	char	**tmp;

	i = 0;
	x = 0;
	if (!nwav[1] && *envp)
		print_tab_a(*envp);
	else
	{
		if (builtin_gestion(&nwav[1], envp) == -1)
		{
			if (binary_gestion(&nwav[1], *envp, "call in function env") == -1)
			{
				if ((tmp = set_env(nwav, envp)))
				{
					print_tab_a(tmp);
					return (tmp);
				}
			}
		}
		else
			return (*envp);
	}
	return (*envp);
}
