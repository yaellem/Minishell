/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:54:49 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/24 01:53:20 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*new;
	size_t	lol;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		new = ft_memalloc(content_size);
		lol = content_size;
		ft_memcpy(new, content, content_size);
		ptr->content = new;
		ptr->content_size = lol;
	}
	ptr->next = NULL;
	return (ptr);
}
