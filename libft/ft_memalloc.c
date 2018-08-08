/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:55:10 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/18 02:10:06 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (size == 0)
		return (0);
	if ((zone = malloc(sizeof(void) * size)) == NULL)
		return (0);
	ft_bzero(zone, size);
	return (zone);
}
