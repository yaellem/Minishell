/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:19:35 by ymarcill          #+#    #+#             */
/*   Updated: 2018/08/30 17:31:01 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_no_access(const char *str)
{
	ft_putstr("cd: ");
	ft_putstr(str);
	ft_putendl(": Permission denied");
	return (0);
}

char	*temp_function(char *str, char **envp)
{
	char	*tmp;
	char	*dst;

	tmp = ft_strdup(str);
	dst = change_dir_special((char*)tmp, envp);
	return (dst);
}

int		ch_dir(char *str, char ***envp)
{
	t_read	r;

	r.dst = temp_function(str, *envp);
	r.ptr = opendir(r.dst);
	if (r.ptr == NULL && lstat(r.dst, &r.buf) == 0)
	{
		ft_putstr("ch_dir: not a directory: ");
		ft_putendl(r.dst);
		return (0);
	}
	if (stat(r.dst, &r.buf) == -1 || !S_ISDIR(r.buf.st_mode))
	{
		ft_putstr("ch_dir: no such file or directory: ");
		ft_putendl(r.dst);
		r.ptr ? closedir(r.ptr) : 0;
		return (0);
	}
	if (!(r.buf.st_mode & S_IXUSR))
		return (ft_no_access(r.dst));
	setold(envp);
	chdir(r.dst);
	setpwd(envp);
	r.ptr ? closedir(r.ptr) : 0;
	free(r.dst);
	return (1);
}
