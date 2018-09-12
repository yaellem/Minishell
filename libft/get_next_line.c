/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:48:32 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 02:56:59 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(t_stat *stat, const int fd, char *buf, char **line)
{
	int ret;

	if (fd < 0 || (!line) || BUFF_SIZE <= 0)
		return (-1);
	if ((stat->j == 0 && fd != 0) || fd == 0)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			if (!(stat->string = ft_strjoin(stat->string, buf)))
				return (-1);
			if (fd == 0 && ft_strchr(buf, '\n'))
				break ;
		}
		if (ret == -1)
			return (-1);
	}
	return (0);
}

int		ft_check(t_stat *stat, char **line)
{
	char	*tmp;

	if (stat->string && !ft_strchr(stat->string, '\n'))
	{
		if (*stat->string == '\0')
		{
			stat->j = 0;
			return (0);
		}
		stat->i = 1;
		(*line) = ft_strdup(stat->string);
		return (1);
	}
	if (stat->string && ft_strchr(stat->string, '\n'))
	{
		(*line) = ft_strndup(stat->string, '\n');
		tmp = ft_strchr(stat->string, '\n') + 1;
		ft_strdel(&stat->str);
		stat->str = ft_strdup(tmp);
		stat->j = 1;
		ft_memdel((void*)&stat->string);
		return (1);
	}
	ft_bzero(&stat, sizeof(t_stat));
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_stat		stat;

	ft_bzero(buf, sizeof(buf));
	if (stat.i == 1)
	{
		ft_bzero(&stat, sizeof(t_stat));
		return (0);
	}
	if (stat.j == 0)
	{
		if (!(stat.string = ft_strnew(1)))
			return (-1);
		ft_bzero(stat.string, 2);
	}
	if ((stat.j == 1 && !(stat.string = ft_strdup(stat.str)))
		||
		(ft_read(&stat, fd, buf, line) == -1))
		return (-1);
	if (ft_check(&stat, line) == 1)
		return (1);
	else
		return (0);
}
