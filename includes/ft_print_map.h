/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:19:23 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/09/20 21:18:56 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_MAP_H
# define FT_PRINT_MAP_H
# include "ft_map.h"

int	ft_write_map(int fd, t_map *map, char *charset);
int	ft_write_ext_map(int fd, t_map *map, char *charset);

#endif
