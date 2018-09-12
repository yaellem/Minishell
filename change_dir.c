/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:19:35 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 16:25:06 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_no_access(char *str)
{
	ft_putstr("cd: ");
	ft_putstr(str);
	ft_strdel(&str);
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

void	chd(char ***envp, char *dst, DIR *ptr)
{
	setold(envp);
	chdir(dst);
	setpwd(envp);
	ptr ? closedir(ptr) : 0;
	ft_strdel(&dst);
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
		ft_strdel(&r.dst);
		return (0);
	}
	if (stat(r.dst, &r.buf) == -1 || !S_ISDIR(r.buf.st_mode))
	{
		ft_putstr("ch_dir: no such file or directory: ");
		ft_putendl(r.dst);
		ft_strdel(&r.dst);
		return (0);
	}
	if (!(r.buf.st_mode & S_IXUSR))
	{
		r.ptr ? closedir(r.ptr) : 0;
		return (ft_no_access(r.dst));
	}
	chd(envp, r.dst, r.ptr);
	return (1);
}
