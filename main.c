/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:46:59 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/09 02:48:48 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	ft_putstr(TEXT_COLOR_RED);
	ft_putstr("-> ");
	ft_putstr(TEXT_COLOR_CYAN);
	pwd_bis();
	ft_putstr(TEXT_COLOR_GREEN);
	ft_putstr(" $> ");
	ft_putstr(TEXT_COLOR_RESET);
}

int		main(int ac, char **av, char **env)
{
	t_env	e;
	t_index	ind;

	ind.x = 0;
	(void)ac;
	(void)av;
	prompt();
	e.nwenv = envrmt(env);
	while (get_next_line(0, &e.line) == 1)
	{
		e.nwav = NULL;
		ind.x = -1;
		e.nwav = e.line[0] != '\0' ? virgule_point(e.line) : e.nwav;
		while (e.nwav != NULL && e.nwav[++ind.x])
		{
			e.nwav[ind.x] = minishell_core(e.nwav[ind.x], e.nwenv);
			if ((builtin_gestion(e.nwav[ind.x], &e.nwenv)) == -1)
				binary_gestion(e.nwav[ind.x], e.nwenv, NULL);
			ft_freetab(e.nwav[ind.x]);
		}
		ft_strdel(&e.line);
		e.nwav ? free(e.nwav) : 0;
		prompt();
	}
	return (0);
}
