/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:14:59 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 21:42:17 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
t_list	*ft_list_init(void)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		list->head = NULL;
	}
	return (list);
}

void	ft_list_free(t_list **list)
{
	t_node	*removed;

	if (list)
	{
		removed = ft_list_pop(*list);
		while (removed)
		{
			ft_node_free(&removed);
			removed = ft_list_pop(*list);
		}
		free(*list);
		*list = NULL;
	}
}

t_node	*ft_list_add(t_list *list, int val)
{
	t_node	*new;

	if (!list)
		return (NULL);
	new = ft_node_init(val);
	if (new)
	{
		new->next = list->head;
		list->head = new;
	}
	return (new);
}

t_node	*ft_list_pop(t_list *list)
{
	t_node	*removed;

	removed = NULL;
	if (list && list->head)
	{
		removed = list->head;
		list->head = removed->next;
	}
	return (removed);
}
