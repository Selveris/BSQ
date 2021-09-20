#include "ft_map.h"
#include "utils.h"
#include <fcntl.h>
#include "ft_error.h"

int	read_header(int fd, t_map *map, char *charset, int *nb_line)
{
	char	buffer;
	int		i;

	if (!read(fd, buffer, 1))
		return (1);
	if (ft_is_numeric(buffer))
		return (1);
	*nb_lines = buffer - '0';
	i = 0;
	while (i < 3)
	{
		read(fd, buffer, 1);
		if (ft_is_printable(buffer))
			charset[i] = buffer;
		else
			return (1);
		i++;
	}
	read(fd, buffer, 1);
	if (buffer != '\n')
		return (1);
	return (0);
}

int	read_first_line(int fd, int *width);
int	read_map(int fd, t_map *map);

t_map	parse_file(char *path)
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
	if (!read_header(fd, map, charset, &height))
		return (ft_null_error("Header not in the norm.\n"));
	if (!read_first_line(fd, map, charset, &width))
		return (ft_null_error("Header not in the norm.\n"));
	map = ft_map_init(width, height);
	if (map == NULL)
		return (ft_null_error("Memory error\n"));
	close(fd);
	fd = open(path, O_RDONLY);
	if (!read_map(fd, map, charset))
		return (ft_null_error("Map not in the norm.\n"));
	close(fd);
	return (map);
}
