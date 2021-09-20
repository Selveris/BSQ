/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:02:28 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/11 22:42:50 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COORDINATE_H
# define FT_COORDINATE_H

typedef struct s_coordinate	t_coord;

t_coord	*init_coord(int x, int y);
void	free_coord(t_coord **coord);
void	ft_getX(t_coord *coord);
void	ft_getY(t_coord *coord);
#endif
