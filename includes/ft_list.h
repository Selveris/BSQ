/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:56:58 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 21:29:55 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct	s_list
{
	t_node	*head;
}	t_list;

t_list	*ft_list_init(void);
void	ft_list_free(t_list **list);
t_node	*ft_list_add(t_list *list, int val);
t_node	*ft_list_pop(t_list *list);

t_node	*ft_node_init(int val);
void	ft_node_free(t_node **node);

#endif
