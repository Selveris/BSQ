/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gluisier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:00:17 by gluisier          #+#    #+#             */
/*   Updated: 2021/09/20 23:33:38 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_parsing.h"
#include "ft_print_map.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;

	map = 0;
	if (argc < 2)
		return (-1);
	map = parse_file(argv[1]);
	printf("%p\n", map);
	ft_write_map(1, map, ".oX");
}
