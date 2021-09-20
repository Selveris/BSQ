/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:08:41 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 22:08:43 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_utils.h"
#include "ft_error.h"
#include "ft_string.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	read_header(int fd, char *charset, int *nb_line)
{
	char	buffer;
	int		i;

	if (!read(fd, &buffer, 1))
		return (1);
	if (ft_is_numeric(buffer))
		return (1);
	*nb_line = buffer - '0';
	i = 0;
	while (i < 3)
	{
		read(fd, &buffer, 1);
		if (ft_is_printable(buffer))
			charset[i] = buffer;
		else
			return (1);
		i++;
	}
	read(fd, &buffer, 1);
	if (buffer != '\n')
		return (1);
	return (0);
}

int	read_first_line(int fd, int *width, char *charset)
{
	char	buffer;
	int		i;

	i = 0;
	read(fd, &buffer, 1);
	while (buffer != '\n')
		read(fd, &buffer, 1);
	read(fd, &buffer, 1);
	while (ft_is_charset(buffer, charset))
	{
		read(fd, &buffer, 1);
		i++;
	}
	if (!ft_is_charset(buffer, charset) || buffer != '\0' || i < 1)
		return (1);
	*width = i;
	return (0);
}

int	ft_read_line(int fd, t_map *map, char *charset, size_t n_line)
{	
	char	buffer;
	size_t	width;
	size_t	i;
	t_coord	*coord;

	ft_map_getdim(map, &width, NULL);
	i = 0;
	while (i < width)
	{	
		read(fd, &buffer, 1);
		if (!ft_is_charset(buffer, charset))
			return (1);
		coord = ft_coord_init(i, n_line);
		if (coord == NULL)
			return (1);
		ft_map_setval(map, coord, ft_get_val_charset(buffer, charset));
		ft_coord_free(&coord);
		i++;
	}
	return (0);
}

int	read_map(int fd, t_map *map, char *charset)
{	
	char	buffer;
	size_t	n_line;
	size_t	height;

	read(fd, NULL, 4);
	ft_map_getdim(map, NULL, &height);
	n_line = 0;
	while (n_line < height)
	{	
		read(fd, &buffer, 1);
		if (buffer != '\n')
			return (1);
		if (ft_read_line(fd, map, charset, n_line))
			return (1);
		n_line++;
	}
	read(fd, &buffer, 1);
	if (buffer != '\0')
		return (1);
	return (0);
}

t_map	*parse_file(char *path)
{
	int		fd;
	int		width;
	int		height;
	char	*charset;
	t_map	*map;

	charset = malloc(sizeof(char) * 4);
	if (charset == NULL)
		return (ft_null_error("Memory error\n"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_null_error("Cannot read file.\n"));
	if (read_header(fd, charset, &height))
		return (ft_null_error("Header not in the norm.\n"));
	if (read_first_line(fd, &width, charset))
		return (ft_null_error("Line not in the norm.\n"));
	map = ft_map_init(width, height);
	if (map == NULL)
		return (ft_null_error("Memory error\n"));
	close(fd);
	fd = open(path, O_RDONLY);
	if (read_map(fd, map, charset))
		return (ft_null_error("Map not in the norm.\n"));
	close(fd);
	return (map);
}
