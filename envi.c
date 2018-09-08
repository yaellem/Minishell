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
	char	**tmp;

	i = 1;
	if (!nwav[1] && *envp)
		print_tab_a(*envp);
	else
	{
		while (nwav[i])
		{
			if (builtin_gestion(&nwav[i], envp) == -1)
			{
				if (binary_gestion(&nwav[i], *envp, "call in function env") != -1)
					return (*envp);
			}
			else
				return (*envp);
			i++;
		}
		if ((tmp = set_env(nwav, envp, "env")))
			return (tmp);
	}
	return (*envp);
}
