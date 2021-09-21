/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:45:03 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 20:07:01 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
# include "ft_coordinate.h"
# include <stddef.h>

typedef struct	s_map
{
	size_t	w;
	size_t	h;
	int		*array;
}	t_map;

t_map	*ft_map_init(size_t w, size_t h);
void	ft_map_free(t_map **map);
int		ft_map_getval(t_map *map, t_coord *coord);
int		ft_map_setval(t_map *map, t_coord *coord, int value);
void	ft_map_getdim(t_map *map, size_t *w, size_t *h);

int	ft_map_getval2(t_map *map, size_t x, size_t y);
int	ft_map_setval2(t_map *map, size_t x, size_t y, int value);

#endif
