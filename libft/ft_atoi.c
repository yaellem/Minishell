/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:47:44 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/17 05:31:56 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	nb;
	long long	x;

	nb = 0;
	x = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		x = 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = (nb * 10 + *str) - 48;
		str++;
	}
	if (x == 1)
		nb = -nb;
	return ((int)nb);
}
