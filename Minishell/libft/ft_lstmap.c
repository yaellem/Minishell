/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 03:24:54 by ymarcill          #+#    #+#             */
/*   Updated: 2017/11/26 01:46:43 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	new = NULL;
	if (lst == NULL || f == NULL)
		return (0);
	if (!(new = f(lst)))
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = f(lst)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
