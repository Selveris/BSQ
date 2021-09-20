/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:19:51 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/09/20 17:19:54 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_atoi(char *s)
{
	int	is_negative;
	int	nb;

	nb = 0;
	is_negative = 1;
	while (is_space(*s))
		s++;
	if ('+' == *s || *s == '-')
	{
		if (*s == '-')
			is_negative = -1;
		s++;
	}
	while (is_numeric(*s))
		nb = (*(s++) - '0') + nb * 10;
	return (is_negative * nb);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		 || c == '\t' || c == '\f')
		return (1);
	return (0);
}

int	ft_is_charset(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}
