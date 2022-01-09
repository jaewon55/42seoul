/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:33:43 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:33:49 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
static void	write_recursive(ssize_t nbr, int base, int *result, char specifier)
{
	char	c;
	int		temp;

	if (*result < 0)
		return ;
	if (nbr >= base)
		write_recursive(nbr / base, base, result, specifier);
	if (nbr % base >= 10)
	{
		if (specifier == 'X')
			c = 'A' + (nbr % base) - 10;
		else
			c = 'a' + (nbr % base) - 10;
	}
	else
		c = '0' + (nbr % base);
	temp = write(1, &c, 1);
	if (temp < 0)
		*result = -1;
	else
		(*result)++;
}

int	write_nbr(ssize_t nbr, int base, char specifier)
{
	int	result;

	result = 0;
	if (nbr < 0)
		nbr *= -1;
	write_recursive(nbr, base, &result, specifier);
	return (result);
}
