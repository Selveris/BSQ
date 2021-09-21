/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:00:17 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/21 14:23:55 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_parsing.h"
#include "ft_print_map.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*charset;

	charset = 0;
	map = 0;
	if (argc < 2)
		return (-1);
	map = parse_file(argv[1], &charset);
	if (!map)
		return (-1);	
	ft_write_map(1, map, charset);
	ft_map_free(&map);
	free(charset);
	while (1);
}
