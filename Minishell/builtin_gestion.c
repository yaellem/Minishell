/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 00:15:26 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/13 00:53:54 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_gestion(char **nwav, char ***env)
{
	int i;
	
	i = 0;
	//if (nwav[0] && (ft_strcmp(nwav[0], "echo")) == 0)
	//	echo(nwav);
	if (nwav[0] && (ft_strcmp(nwav[0], "cd")) == 0)
		ch_dir(nwav[1], env);
	else if (nwav[0] && (ft_strcmp(nwav[0], "exit")) == 0)
		nwav[1] ? exit(ft_atoi(nwav[1])) : exit(0);
	//if (nwav[0] && (ft_strcmp(nwav[0], "setenv")) == 0)
	//	setenv(nwav);
	//if (nwav[0] && (ft_strcmp(nwav[0], "unsetenv")) == 0)
	//	unsetenv(nwav[1]);
	else if (nwav[0] && (ft_strcmp(nwav[0], "env")) == 0)
		print_tab_a(*env);
	else if (nwav[0] && (ft_strcmp(nwav[0], "pwd")) == 0)
		pwd(nwav);
}
