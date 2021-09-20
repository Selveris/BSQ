/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:58:33 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 17:19:45 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct s_coordinate
{
	unsigned int	x;
	unsigned int	y;
}	t_coord;

t_coord	*init_coord(int x, int y)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

void	free_coord(t_coord **coord)
{
	free(*coord);
	*coord = NULL;
}

void	ft_getx(t_coord *coord)
{
	return (coord->x);
}

void	ft_gety(t_coord *coord)
{
	return (coord->y);
}
