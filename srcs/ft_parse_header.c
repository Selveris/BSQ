/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:30:06 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 22:40:43 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"
#include "ft_list.h"
#include "ft_utils.h"
#include "ft_string.h"
#include "ft_error.h"
#include "ft_map.h"
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 256

int	read_header(int fd, char *charset, size_t *nb_line)
{
	char	buffer[BUF_SIZE];
	int		i;

	i = 0;
	read(fd, buffer, 1);
	while (i < BUF_SIZE && ft_is_numeric(buffer[i]))
		read(fd, buffer + ++i, 1);
	if (i == 0)
		return (-1);
	*nb_line = ft_atoi(buffer);
	buffer[0] = buffer[i];
	read(fd, buffer + 1, 3);
	i = 0;
	while (i < 3)
	{
		if (ft_is_printable(buffer[i]))
			charset[i] = buffer[i];
		else
			return (1);
		++i;
	}
	charset[i] = '\0';
	if (buffer[i] != '\n')
		return (1);
	return (0);
}

int	read_first_line(int fd, size_t *nb_col, char *charset, t_list	*walls)
{
	char	buffer;
	size_t	i;

	i = 0;
	read(fd, &buffer, 1);
	while (ft_is_charset(buffer, charset))
	{
		if (buffer == charset[1])
			ft_list_add(walls, i);
		read(fd, &buffer, 1);
		++i;
	}
	if ((buffer != '\n' && buffer != '\0') || i == 0)
		return (1);
	*nb_col = i;
	return (0);
}

void	add_first_walls(t_map *map, t_list *walls)
{
	size_t	i;
	t_node	*node;

	node = ft_list_pop(walls);
	while (node)
	{
		ft_map_setval2(map, node->val, 0, 1);
		ft_node_free(&node);
		node = ft_list_pop(walls);
	}
	i = 0;
	while (i < map->w)
	{
		if (ft_map_getval2(map, i, 0) != 1)
		{
			ft_map_setval2(map, i, 0, 0);
		}
		++i;
	}
}

t_map *parse_header(int fd, char *charset)
{
	size_t	nb_line;
	size_t	nb_col;
	t_map	*map;
	t_list	*walls;

	walls = ft_list_init();
	if (!walls)
		return (ft_null_error("Memory error (list)"));
	if(read_header(fd, charset, &nb_line))
		return (ft_null_error("Header not in the norms"));
	if(read_first_line(fd, &nb_col, charset, walls))
		return (ft_null_error("First line not in the norms"));
	map = ft_map_init(nb_col, nb_line, charset);
	if (!map)
		return (ft_null_error("Memory error (map)"));
	add_first_walls(map, walls);
	ft_list_free(&walls);
	return (map);
}
