/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:10:44 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/30 03:58:37 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	int					i;
	unsigned int		j;
	unsigned int		z;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	z = i;
	if (s[i] == '\0')
		return (ft_strdup(""));
	while (s[i + 1])
		i++;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	j = i;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (j - z + 2))))
		return (NULL);
	while (z <= j)
		str[i++] = s[z++];
	str[i] = '\0';
	return (str);
}
