/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:51:13 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/13 01:00:32 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*change_dir_special(char *str, char **envp)
{
	t_env	e;
	int i;

	i = 0;

	//e.tmp = NULL;
	if (str && ft_strcmp(str, "-") == 0)
	{
		ft_putendl(tiret(envp));
		str = tiret(envp);
	}
	if (str && str[1] && str[0] == '~')
	{
		if (str[1] && str[1] == '-' && !str[2])
			str = tiret(envp);
		else
		{
			e.tmp = ft_strsplit(str, '/');
			free(e.tmp[0]);
			e.tmp[0] = ft_strdup(tilde(envp));
			str = ft_strdup(e.tmp[0]);
			while (e.tmp[++i])
			{
				str = ft_strjoinnf(str, "/");
				str = ft_strjoinnf(str, e.tmp[i]);
			}
		}
	}
	!str || (ft_strcmp(str, "~")) == 0 ? str = tilde(envp) : 0;
	return (str);
}
