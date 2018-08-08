/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:46:00 by ymarcill          #+#    #+#             */
/*   Updated: 2018/02/03 19:52:08 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 5

typedef	struct	s_stat
{
	int			i;
	char		*string;
	char		*str;
	int			j;
}				t_stat;

int				get_next_line(const int fd, char **line);

#endif
