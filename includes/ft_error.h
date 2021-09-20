/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:46:59 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/09/20 21:18:29 by gluisier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef enum	e_error
{
	SUCCESS,
	ERR_WRITE,
	ERR_READ,
	ERR_FILE,
	ERR_MAP_INDEX,
	ERR_NULL_POINTER,
	ERR_MEM,
	SIZE
}	t_error;

void	*ft_null_error(char *s);

#endif
