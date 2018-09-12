/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:53:14 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 20:11:18 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*if_dollar(char *str, char **envp, char *dst, int x)
{
	t_env	env;
	t_index	ind;

	ind.test = 0;
	ind.i = -1;
	env.strim = trim(&str[x + 1]);
	ind.y = !str[x + 1] ? 1 : ind.y;
	while (envp[++ind.i])
	{
		env.tmp = ft_strsplit(envp[ind.i], '=');
		if (ft_strcmp(env.tmp[0], env.strim) == 0)
		{
			env.temp = ft_strdup(&str[x + ft_strlen(env.tmp[0])]);
			ind.y == 0 ? dst = ft_strndup(str, '$') : 0;
			ind.test = 1;
			ind.y = 1;
			dst = is_good_end(env.temp, dst, env.tmp[1]);
			free(env.temp);
		}
		ft_freetab(env.tmp);
	}
	if (ind.test == 0)
		dst = if_not_var(env.strim, str, dst, x);
	free(env.strim);
	return (dst);
}

char	*is_good_end(char *temp, char *dst, char *tmp)
{
	char	*tmp2;

	dst = ft_strjoin(dst, tmp);
	if (temp[1] == '/' || (temp[1] == '$' && (temp[2] == '/' || temp[2] == ','
	|| !temp[2])) || temp[1] == ',')
	{
		if (!temp[2] || is_char(&temp[1], '$') == 0 || (temp[2] == '$' &&
		!temp[3]))
			dst = ft_strjoin(dst, &temp[1]);
		else
		{
			tmp2 = ft_strndup(&temp[1], '$');
			dst = ft_strjoin(dst, tmp2);
			free(tmp2);
		}
	}
	return (dst);
}

char	*if_not_var(char *strim, char *str, char *dst, int x)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(&str[x + 1 + ft_strlen(strim)]);
	if (is_char(tmp, '$'))
		tmp2 = ft_strndup(tmp, '$');
	else
		tmp2 = ft_strdup(tmp);
	dst = ft_strjoin(dst, tmp2);
	free(tmp);
	free(tmp2);
	return (dst);
}
