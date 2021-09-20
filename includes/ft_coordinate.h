/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:02:28 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 19:26:26 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COORDINATE_H
# define FT_COORDINATE_H
# include <stddef.h>

typedef struct s_coordinate	t_coord;

t_coord	*ft_coord_init(int x, int y);
void	ft_coord_free(t_coord **coord);
size_t	ft_coord_x(t_coord *coord);
size_t	ft_coord_y(t_coord *coord);
size_t	ft_coord_1d(t_coord *coord, size_t width, size_t height);

#endif
