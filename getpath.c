/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:32:33 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 02:21:22 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_line(char **env)
{
	char	**tmp;
	char	**path;
	int		i;

	i = 0;
	tmp = NULL;
	path = NULL;
	while (env && env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		if ((ft_strcmp(tmp[0], "PATH")) == 0)
		{
			path = ft_strsplit(tmp[1], ':');
			ft_freetab(tmp);
			break ;
		}
		i++;
		ft_freetab(tmp);
	}
	return (path);
}

char	*getpath(char **nwav, char **path)
{
	int		i;
	t_read	r;
	char	*command;

	i = -1;
	command = NULL;
	while (path && path[++i])
	{
		r.ptr = opendir(path[i]);
		while (r.ptr && (r.file = readdir(r.ptr)))
		{
			if ((ft_strcmp(r.file->d_name, nwav[0])) == 0)
			{
				command = ft_strjoinnf(path[i], "/");
				command = ft_strjoin(command, nwav[0]);
				break ;
			}
		}
		r.ptr ? closedir(r.ptr) : 0;
	}
	return (command);
}
