/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:00:41 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 21:01:05 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_node	*ft_node_init(int val)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node)
		node->val = val;
	return (node);
}

void	ft_node_free(t_node **node)
{
	if (node)
	{
		free(*node);
		*node = NULL;
	}
}
