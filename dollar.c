/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:36:59 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/03 23:29:22 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
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
	*x = 0;
	*y = 0;
	*z = 0;
	return (test);
}

/*char	*test_env(char	**envp, char *strim, int y, char *str)
  {

  }*/
int     is_char(char *str, char c)
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

	str = ft_strdup(string);
	ind.test = init_var(&ind.i, &ind.x, &ind.y, &ind.z);
	while (str[++ind.i])
	{
		if (str[ind.i] == '$')
			ind.x = 1;
	}
	if (ind.x == 0)
		return (str);
	ind.x = -1;
	ind.i = -1;
	env.dst = NULL;
	while (str && str[++ind.x])
	{
		if (str[ind.x] == '$')
		{
			ind.z = 1;
			env.strim = trim(&str[ind.x + 1]);
			ind.y = !str[ind.x + 1] ? 1 : ind.y;
			while (envp[++ind.i])
			{
				env.tmp = ft_strsplit(envp[ind.i], '=');
				if (ft_strcmp(env.tmp[0], env.strim) == 0)
				{
					env.temp = ft_strdup(&str[ind.x + ft_strlen(env.tmp[0])]);
					ind.y == 0 ? env.dst = ft_strndup(str, '$') : 0;
					ind.test = 1;
					ind.y = 1;
					env.dst = ft_strjoin(env.dst, env.tmp[1]);
				//	ft_putstr("dst :    ");
				//	ft_putendl(env.dst);
				//	ft_putstr("le reste :   ");
				//	ft_putendl(env.temp);
					if ((env.temp[1] == '/' || (env.temp[1] == '$' &&
						(env.temp[2] == '/' || env.temp[2] == ',' ||
						!env.temp[2])) || env.temp[1] == ','))
					{

						if (!env.temp[2] || is_char(&env.temp[1], '$') == 0)
							env.dst = ft_strjoin(env.dst, &env.temp[1]);
						else
						{
							free(env.strim);
					//	if (is_char(&env.temp[1], '$'))
							env.strim = ft_strndup(&env.temp[1], '$');
				//			ft_putstr("strim :  ");
				//			ft_putendl(env.strim);
						//else
						//	env.strim = ft_strdup(&env.temp[1]);
						env.dst = ft_strjoin(env.dst, env.strim);
						}
					}
					free(env.temp);
				}
				ft_freetab(env.tmp);
			}
			if (ind.test == 0)
			{
				env.temp = ft_strdup(&str[ind.x + 1 + ft_strlen(env.strim)]);
				ft_putendl(env.temp);
				free(env.strim);
				env.strim = ft_strndup(env.temp, '$');
				env.dst = ft_strjoin(env.dst, env.strim);
			}
			ind.test = 0;
			free(env.strim);
		}
		ind.i = -1;
	}
	env.dst ? free(str) : 0;
	//ft_putendl(env.dst);
	return (env.dst ? env.dst : str);
}
