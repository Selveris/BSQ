/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:58:33 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 21:50:02 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coordinate.h"
#include <stddef.h>
#include <stdlib.h>

struct s_coordinate
{
	size_t	x;
	size_t	y;
};

t_coord	*ft_coord_init(int x, int y)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	if (coord == NULL)
		return (NULL);
	coord->x = x;
	coord->y = y;
	return (coord);
}

void	ft_coord_free(t_coord **coord)
{
	free(*coord);
	*coord = NULL;
}

size_t	ft_coord_x(t_coord *coord)
{
	return (coord->x);
}

size_t	ft_coord_y(t_coord *coord)
{
	return (coord->y);
}

size_t	ft_coord_1d(t_coord *coord, size_t width)
{
	return (width * coord->y + coord->x);
}
