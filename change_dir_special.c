/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:51:13 by ymarcill          #+#    #+#             */
/*   Updated: 2018/08/04 20:37:07 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*change_dir_special(char *str, char **envp)
{
	t_env	e;
	int i;
	char *dst;

	i = 0;
	dst = NULL;
	if (str && ft_strcmp(str, "-") == 0)
	{
		ft_putendl(tiret(envp));
		ft_strdel(&str);
		str = tiret(envp);
	}
	if (str && str[1] && str[0] == '~')
	{
		if (str[1] && str[1] == '-' && !str[2])
		{
			ft_strdel(&str);
			str = tiret(envp);			
		}
		else
		{
			e.tmp = ft_strsplit(str, '/');
			free(e.tmp[0]);
			e.tmp[0] = ft_strdup(tilde(envp));
			ft_strdel(&str);
			str = ft_strdup(e.tmp[0]);
			while (e.tmp[++i])
			{
				str = ft_strjoinnf(str, "/");
				str = ft_strjoinnf(str, e.tmp[i]);
			}
		}
	}
	if (!str || (ft_strcmp(str, "~")) == 0)
	{
	  // ft_strdel(&str);
	   str = tilde(envp);
	}
	return (str);
}
