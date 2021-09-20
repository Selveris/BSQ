/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:52:40 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 20:06:24 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

struct	s_map
{
	size_t	w;
	size_t	h;
	int		*array;
};

t_map	*ft_map_init(size_t w, size_t h)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	map->w = w;
	map->h = h;
	map->array = malloc(sizeof(*(map->array)) * (w * h));
	if (!map->array)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

void	ft_map_free(t_map **map)
{
	free((*map)->array);
	free(*map);
	*map = NULL;
}

int	ft_map_getval(t_map *map, t_coord *coord)
{
	if (ft_coord_x(coord) >= map->w || ft_coord_y(coord) >= map->h)
		return (-1);
	return (map->array[ft_coord_1d(coord, map->w)]);
}

int	ft_map_setval(t_map *map, t_coord *coord, int value)
{
	if (value < 0)
		return (-1);
	if (ft_coord_x(coord) >= map->w || ft_coord_y(coord) >= map->h)
		return (-1);
	map->array[ft_coord_1d(coord, map->w)] = value;
	return (0);
}

void	ft_map_getdim(t_map *map, size_t *w, size_t *h)
{
	if (map)
	{
		*w = map->w;
		*h = map->h;
	}
}
