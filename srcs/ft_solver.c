#include "ft_map.h"
#include "ft_coordinate.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_square
{
	size_t x;
	size_t y;
	size_t dim;

}	t_square;

t_square	*sq_init(size_t x, size_t y, size_t dim)
{
	t_square *sq;

	sq = malloc(sizeof(t_square));
	if (sq == NULL)
		return (NULL);
	sq->x = x;
	sq->y = y;
	sq->dim = dim;
	return (sq);
}

void set_sq(t_square *sq, size_t x, size_t y, size_t dim)
{
	sq->x = x;
	sq->y = y;
	sq->dim = dim;
}

int	check_validity(t_map *map, size_t x, size_t y, size_t dim)
{
	size_t i;
	size_t j;
	size_t dim_x;
	size_t dim_y;

	j = 0;
	ft_map_getdim(map, &dim_x, &dim_y);
	if ((x + dim - 1 >= dim_x) || (y + dim - 1 >= dim_y))
		return (0);
	while (j < dim)
	{	
		i = 0;
		while (i < dim)
		{
			if (ft_map_getval2(map, x + i, y + j) == 1)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void get_max_sq(t_map *map, t_square *sq, size_t x, size_t y)
{
	size_t dim;

	dim = sq->dim;
	while (check_validity(map, x, y, dim))
	{
		printf(" %d, %d, dim : %d\n", (int) sq->x, (int) sq->y, (int) sq->dim);
		set_sq(sq, x, y, dim);
		dim++;
	}
}

t_square	*solve_map(t_map *map, t_square *sq)
{
	size_t i;
	size_t j;

	j = 0;
	if (sq == NULL)
		return (NULL);
	while (j < map->h)
	{	
		i = 0;
		while (i < map->w)
		{	
			if (ft_map_getval2(map, i, j) == 0)
				get_max_sq(map, sq, i, j);
			i++;
		}
		j++;
	}
	return (sq);
}

int write_sqtomap(t_map *map)
{	
	size_t x;
	size_t y;

	t_square *sq;

	sq = sq_init(0, 0, 0);
	if (sq == NULL)
		return (1);
	sq = solve_map(map, sq);
	y = sq->y;
	printf(" %d, %d, dim : %d\n", (int) sq->x, (int) sq->y, (int) sq->dim);
	while (y < sq->y + sq->dim)
	{
		x = sq->x;
		while (x < sq->x + sq->dim)
		{
			ft_map_setval2(map, x, y, 2);
			x++;
		}
		y++;
	}
	free(sq);
	return (0);
}
