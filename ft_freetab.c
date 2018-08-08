/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:49:41 by ymarcill          #+#    #+#             */
/*   Updated: 2018/08/04 20:16:35 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freetab(char **s1)
{
	int i;

	i = 0;
	while (s1 && s1[i])
	{
		s1 ? free(s1[i]) : 0;
		i++;
	}
	free(s1);
	s1 = NULL;
}

void	ft_freetrtab(char ***s1)
{
	int i;

	i = 0;
	while (s1[i])
	{
		s1[i] ? ft_freetab(s1[i]) : 0;
		s1[i] = NULL;
		i++;
	}
	free(s1);
	s1 = NULL;
}
