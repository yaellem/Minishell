/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 05:58:46 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/29 04:10:30 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int p;

	p = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		p++;
	}
	return (p);
}

char			*ft_itoa(int n)
{
	char		*str;
	long int	a;
	int			j;

	j = 0;
	a = (long int)n;
	if (a < 0)
	{
		a = -a;
		j = 1;
	}
	if (!(str = (char *)malloc(sizeof(char) * ((j += ft_size(n)) + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[j--] = '\0';
	while (a > 0)
	{
		str[j] = a % 10 + 48;
		a /= 10;
		j--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
