/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:30:57 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/05 20:30:58 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdupn(char *str, char c)
{
	char	*dst;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			dst = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
			while (str[++i])
				dst[j++] = str[i];
			dst[j] = '\0';
			return (dst);
		}
		i--;
	}
	return (NULL);
}

char	*ft_strldup(char *str, char c)
{
	char	*dst;
	int		i;
	int		j;
	int		index;

	j = 0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			index = i;
			i = 0;
			dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
			while (i <= index)
				dst[j++] = str[i++];
			dst[j] = '\0';
			return (dst);
		}
		i--;
	}
	return (NULL);
}

char	*ft_strinddup(char *str, char c)
{
	char	*dst;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			dst = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
			while (str[i])
				dst[j++] = str[i++];
			dst[j] = '\0';
			return (dst);
		}
		i--;
	}
	return (str);
}
