/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:43:47 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/05 19:53:48 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		permissions(char **str, struct stat buf)
{
	int	i;

	i = 0;
	if (stat(*str, &buf) == 0 && (S_IXUSR & buf.st_mode) == 0)
	{
		ft_putstr("Minishell: Permission denied: ");
		ft_putendl(*str);
		i = 1;
		*str = NULL;
	}
	return (i);
}

void	execution(char *str, char **nwav, char **nwenv, int *i)
{
	pid_t	pid;

	if (str)
	{
		pid = fork();
		if (pid == 0)
			execve(str, nwav, nwenv);
		else
			wait(NULL);
		*i = 0;
	}
	else
	{
		if (*i == 0)
		{
			ft_putstr("Minishell: command not found: ");
			ft_putendl(nwav[0]);
		}
	}
}

char	*file_execution(DIR *ptr, int *i, char *str, char *nwav)
{
	t_read	r;
	char	*tmp;

	while (ptr && (r.file = readdir(ptr)))
	{
		tmp = ft_strdupn(nwav, '/');
		if (tmp && ft_strcmp(tmp, r.file->d_name) == 0)
		{
			str ? free(str) : 0;
			str = ft_strdup(nwav);
			*i = permissions(&str, r.buf);
			ft_strdel(&tmp);
			break ;
		}
		ft_strdel(&tmp);
	}
	return (str);
}

char	*check_function_call(char *dst, int *check)
{
	if (dst && ft_strcmp(dst, "call in function env") == 0)
	{
		*check = 1;
		free(dst);
		dst = NULL;
	}
	return (dst);
}

int		binary_gestion(char **nwav, char **nwenv, char *str)
{
	t_read	r;
	t_index	ind;

	ind.i = 0;
	ind.check = 0;
	r.dst = ft_strdup(str);
	r.path = ft_strldup(nwav[0], '/');
	r.ptr = r.path ? opendir(r.path) : opendir(".");
	r.path ? free(r.path) : 0;
	r.dst = check_function_call(r.dst, &ind.check);
	r.dst = file_execution(r.ptr, &ind.i, r.dst, nwav[0]);
	r.ptr ? closedir(r.ptr) : 0;
	r.getl = get_line(nwenv);
	if ((r.getp = getpath(nwav, r.getl)))
	{
		ft_strdel(&r.dst);
		r.dst = getpath(nwav, r.getl);
	}
	if (ind.check == 1)
		ind.i = -1;
	execution(r.dst, nwav, nwenv, &ind.i);
	r.getp ? free(r.getp) : 0;
	ft_strdel(&r.dst);
	ft_freetab(r.getl);
	return (ind.i);
}
