/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:53:19 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/08 22:48:46 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_built(char *str)
{
	int i;

	i = -1;
	if (str && ft_strcmp(str, "cd") == 0)
		i = 0;
	if (str && ft_strcmp(str, "echo") == 0)
		i = 0;
	if (str && ft_strcmp(str, "exit") == 0)
		i = 0;
	if (str && ft_strcmp(str, "env") == 0)
		i = 0;
	if (str && ft_strcmp(str, "setenv") == 0)
		i = 0;
	if (str && ft_strcmp(str, "unsetenv") == 0)
		i = 0;
	return (i);
}

int		fork_env(char **nwav, char ***envp)
{
	pid_t	father;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (nwav[++i])
	{
		father = fork();
		if (father == 0)
		{
			builtin_gestion(&nwav[i], envp);
			exit(0);
		}
		wait(NULL);
		if (check_built(nwav[i]) == -1)
		{
			if (binary_gestion(&nwav[i], *envp, "call in function env") != -1)
				return (x = 1);
		}
		else
			return (x = 1);
	}
	return (x);
}

char	**envi(char ***envp, char **nwav)
{
	int		i;
	pid_t	father;
	char	**tmp;

	i = 0;
	!nwav[1] && *envp ? print_tab_a(*envp) : 0;
	if (nwav[1] && *envp)
	{
		if (fork_env(nwav, envp) == 1)
			return (*envp);
		while (nwav[++i])
		{	
			if (is_char(nwav[i], '='))
			{
				father = fork();
				if (father == 0)
				{
					tmp = set_env(nwav, envp, "env");
					print_tab_a(tmp);
					exit(0);
				}
				wait(NULL);
				return (*envp);
			}
			ft_putendl("env: There is not the character '='");
		}
	}
	return (*envp);
}
