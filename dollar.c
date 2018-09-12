/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:36:59 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 20:13:30 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		exit(-1);
	while (str[i] && (str[i] != '/' && str[i] != '$' && str[i] != ','))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		init_var(int *i, int *x, int *y, int *z)
{
	int		test;

	test = 0;
	*i = -1;
	*x = -1;
	*y = 0;
	*z = 0;
	return (test);
}

int		is_char(char *str, char c)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == c)
			j = 1;
	}
	return (j);
}

char	*dollar(char *string, char **envp)
{
	t_index		ind;
	t_env		env;
	char		*str;

	env.dst = NULL;
	str = ft_strdup(string);
	ind.test = init_var(&ind.i, &ind.x, &ind.y, &ind.z);
	if (is_char(str, '$') == 0)
		return (str);
	while (str && str[++ind.x])
	{
		if (str[ind.x] == '$')
			env.dst = if_dollar(str, envp, env.dst, ind.x);
		ind.i = -1;
	}
	env.dst ? free(str) : 0;
	return (env.dst ? env.dst : str);
}
