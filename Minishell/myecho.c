/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:39:20 by ymarcill          #+#    #+#             */
/*   Updated: 2018/07/22 09:13:14 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	myecho(char **nwav)
{
	int	i;
	int	j;
	int	opt;

	i = 1;
	j = 0;
	opt = 0;
	if (ft_strcmp(nwav[i], "-n") == 0)
	{
		opt = 1;
		i++;
	}
	while (nwav[i])
	{
		while (nwav[i][j])
		{
				ft_putchar(nwav[i][j]);
				j++;
		}
		if (nwav[i + 1])
			ft_putchar(' ');
		j = 0;
		i++;
	}
	if (opt == 0)
		ft_putchar('\n');
	else if (opt && nwav[2])
	{
		ft_putstr("\x1b[30;47m%");
		ft_putendl("\x1b[0m");
	}
}
