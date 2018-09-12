/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:51:13 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 16:21:28 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_tiret(char *str, char **envp)
{
	if (str && ft_strcmp(str, "-") == 0)
	{
		ft_strdel(&str);
		str = tiret(envp);
		ft_putendl(str);
	}
	return (str);
}

char	*change_dir_special(char *str, char **envp)
{
	int		i;

	i = 0;
	str = str_tiret(str, envp);
	if (str && str[1] && str[0] == '~')
	{
		if (str[1] && str[1] == '-' && !str[2])
		{
			ft_strdel(&str);
			str = tiret(envp);
		}
	}
	!str || (ft_strcmp(str, "~")) == 0 ? str = tilde(envp) : 0;
	return (str);
}
