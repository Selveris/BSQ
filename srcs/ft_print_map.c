/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:24:38 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 00:07:55 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_error.h"
#include "ft_coordinate.h"
#include "ft_map.h"
#include "ft_string.h"

t_error	ft_write_line(int fd, t_map *map, char *charset, size_t line_nb)
{
	size_t	w;
	size_t	x;
	int		val;
	t_coord	*coord;

	ft_map_getdim(map, &w, NULL);
	x = 0;
	while (x < w)
	{
		coord = ft_coord_init(x, line_nb);
		if (!coord)
			return (ERR_MEM);
		val = ft_map_getval(map, coord);
		write(fd, charset + val, 1);
		ft_coord_free(&coord);
		++x;
	}
	write(fd, "\n", 1);
	return (SUCCESS);
}

t_error	ft_write_map(int fd, t_map *map, char *charset)
{	
	size_t	h;
	size_t	y;
	t_error	err;

	ft_map_getdim(map, NULL, &h);
	y = 0;
	while (y < h)
	{
		err = ft_write_line(fd, map, charset, y);
		if (err)
			return (err);
		++y;
	}
	return (SUCCESS);
}

t_error	ft_write_ext_line(int fd, t_map *map, char *charset, size_t line_nb)
{
	size_t	w;
	size_t	x;
	int		val;
	t_coord	*coord;

	ft_map_getdim(map, &w, NULL);
	x = 0;
	while (x < w)
	{
		coord = ft_coord_init(x, line_nb);
		if (!coord)
			return (ERR_MEM);
		val = ft_map_getval(map, coord);
		write(fd, charset + val, 1);
		if (x < w - 1)
			write(fd, " ", 1);
		ft_coord_free(&coord);
		++x;
	}
	ft_putchar('\n');
	return (SUCCESS);
}

t_error	ft_write_ext_map(int fd, t_map *map, char *charset)
{
	size_t	h;
	size_t	y;
	t_error	err;

	ft_map_getdim(map, NULL, &h);
	y = 0;
	while (y < h)
	{
		err = ft_write_ext_line(fd, map, charset, y);
		if (err)
			return (err);
		++y;
	}
	return (SUCCESS);
}
