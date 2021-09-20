/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:20:00 by bgoncalv          #+#    #+#             */
/*   Updated: 2021/09/20 17:20:02 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_is_printable(char c)
{
	return (' ' <= c && c <= '~');
}

int	ft_get_val_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
