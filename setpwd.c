/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:00:34 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 02:01:35 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setpwd(char ***envp)
{
	t_read	r;
	t_env	e;
	char	*str;
	int		i;

	e.nwenv = *envp;
	r.getp = NULL;
	i = 0;
	while (e.nwenv[i])
	{
		e.tmp = ft_strsplit(e.nwenv[i], '=');
		if ((ft_strcmp(e.tmp[0], "PWD")) == 0)
		{
			free(e.nwenv[i]);
			e.nwenv[i] = ft_strdup("PWD=");
			str = getcwd(r.getp, 255);
			e.nwenv[i] = ft_strjoin(e.nwenv[i], str);
			free(str);
			ft_freetab(e.tmp);
			break ;
		}
		i++;
		ft_freetab(e.tmp);
	}
}
