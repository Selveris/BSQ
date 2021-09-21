/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:08:41 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 22:40:45 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"
#include "ft_map.h"
#include "ft_utils.h"
#include "ft_error.h"
#include "ft_string.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
int	ft_read_line(int fd, t_map *map, char *charset, size_t n_line)
{	
	char	*buffer;
	size_t	width;
	size_t	i;
	t_coord	*coord;

	ft_map_getdim(map, &width, NULL);
	buffer = malloc (sizeof(char) * width);
	if (!buffer || (int) width != read(fd, buffer, width))
		return (1);
	i = 0;
	while (i < width)
	{	
		if (!ft_is_charset(buffer[i], charset))
			return (1);
		coord = ft_coord_init(i, n_line);
		if (coord == NULL)
			return (1);
		ft_map_setval(map, coord, ft_get_val_charset(buffer[i], charset));
		ft_coord_free(&coord);
		i++;
	}
	free(buffer);
	return (0);
}

int	read_map(int fd, t_map *map, char *charset)
{	
	char	buffer;
	size_t	n_line;
	size_t	height;

	ft_map_getdim(map, NULL, &height);
	n_line = 1;
	while (n_line < height)
	{	
		if (ft_read_line(fd, map, charset, n_line))
			return (1);
		read(fd, &buffer, 1);
		if (buffer != '\n')
			return (1);
		n_line++;
	}
	read(fd, &buffer, 1);
	if (buffer != '\n')
		return (1);
	return (0);
}

t_map	*parse_file(char *path, char **charset)
{
	int		fd;
	t_map	*map;

	fd = open(path, O_RDONLY);
	*charset = malloc(sizeof(char) * 4);
	if (fd == -1 || *charset == NULL)
		return (ft_null_error("Memory error\n"));
	map = parse_header(fd, *charset);
	if (map == NULL)
		return (ft_null_error("Error parsing header.\n"));
	if (read_map(fd, map, *charset))
		return (ft_null_error("Map not in the norm.\n"));
	close(fd);
	return (map);
}
