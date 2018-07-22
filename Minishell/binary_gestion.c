/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 23:43:47 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/21 00:00:13 by ymarcill         ###   ########.fr       */
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

void	execution(char *str, char **nwav, char **nwenv, int i)
{
	pid_t	pid;

	if (str)
	{
		pid = fork();
		if (pid == 0)
			execve(str, nwav, nwenv);
		else
			wait(NULL);
	}
	else
	{
		if (i == 0)
		{
			ft_putstr("Minishell: command not found: ");
			ft_putendl(nwav[0]);
		}
	}
}

void	binary_gestion(char **nwav, char **nwenv, char *str)
{
	t_read	r;
	int		i;

	i = 0;
	r.ptr = opendir(".");
	while (r.ptr && (r.file = readdir(r.ptr)))
	{
		if (ft_strcmp(&(nwav[0][2]), r.file->d_name) == 0)
		{
			str = ft_strdup(&(nwav[0][2]));
			i = permissions(&str, r.buf);
			break ;
		}
	}
	if (getpath(nwav, get_line(nwenv)))
		str = getpath(nwav, get_line(nwenv));
	execution(str, nwav, nwenv, i);
}
