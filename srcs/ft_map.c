/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:52:40 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 20:32:37 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>
#include "ft_map.h"

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

int	ft_map_getval2(t_map *map, size_t x, size_t y)
{
	if (x >= map->w || y >= map->h)
		return (-1);
	return map->array[(y * map->w + x)];
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

int	ft_map_setval2(t_map *map, size_t x, size_t y, int value)
{
	if (value < 0)
		return (-1);
	if (x >= map->w || y >= map->h)
		return (-1);
	map->array[y * map->w + x] = value;
	return (0);
}

void	ft_map_getdim(t_map *map, size_t *w, size_t *h)
{
	if (map)
	{
		if (w)
			*w = map->w;
		if (h)
			*h = map->h;
	}
}
