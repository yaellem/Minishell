/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:43:47 by ymarcill          #+#    #+#             */
/*   Updated: 2018/08/01 00:34:37 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		permissions(char **str, struct stat buf)
{
	int	i;

	i = 0;
	stat(*str, &buf);
	if (!(S_IXUSR & buf.st_mode))
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

int		binary_gestion(char **nwav, char **nwenv, char *str)
{
	t_read	r;
	int		i;
	int		check;

	i = 0;
	check = 0;
	r.ptr = opendir(".");
	if (str && ft_strcmp(str, "called in function env") == 0)
	{
		check = 1;
		str = NULL;
	}
	while (r.ptr && (r.file = readdir(r.ptr)))
	{
		if (ft_strcmp(&(nwav[0][2]), r.file->d_name) == 0)
		{
			str ? free(str) : 0;
			str = ft_strdup(&(nwav[0][2]));
			i = permissions(&str, r.buf);
			break ;
		}
	}
	if (getpath(nwav, get_line(nwenv)))
		str = getpath(nwav, get_line(nwenv));
	if (check == 1)
		i = -1;
	execution(str, nwav, nwenv, &i);
	return (i);
}
