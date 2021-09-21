#ifndef FT_SOLVER_H
# define FT_SOLVER_H
# include "ft_map.h"

typedef struct s_square
{
	size_t x;
	size_t y;
	size_t dim;

}	t_square;

t_square	*sq_init(size_t x, size_t y, size_t dim);
void set_sq(t_square *sq, size_t x, size_t y, size_t dim);
t_square	*solve_map(t_map *map, t_square *sq);
void get_max_sq(t_map *map, t_square *sq, size_t x, size_t y);
int write_sqtomap(t_map *map);
int	check_validity(t_map *map, size_t x, size_t y, size_t dim);

#endif