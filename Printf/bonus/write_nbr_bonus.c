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

#include "ft_printf_bonus.h"
static void	ft_recursive(unsigned long nbr, int base, int *result, char spe)
{
	char	c;
	int		temp;

	if (nbr >= (unsigned int)base)
		ft_recursive(nbr / base, base, result, spe);
	if (*result < 0)
		return ;
	if (!nbr)
		c = '0';
	else if (nbr % base >= 10)
	{
		if (spe == 'X')
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

int	write_nbr(ssize_t nbr, char spe)
{
	int	result;
	int	base;

	result = 0;
	if (spe == 'i' || spe == 'd' || spe == 'u')
		base = 10;
	else
		base = 16;
	if ((spe == 'i' || spe == 'd') && nbr < 0)
	{
		result = write(1, "-", 1);
		if (result < 0)
			return (-1);
		nbr *= -1;
	}
	ft_recursive(nbr, base, &result, spe);
	return (result);
}
