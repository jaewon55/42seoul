/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:33:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:33:09 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	nbr_len(ssize_t nbr, char spe, int *flags)
{
	int				result;
	int				base;
	unsigned long	temp;

	if (flags[PRECISION] < 0 && nbr == 0)
		return (0);
	else if (!nbr)
		return (1);
	if (spe == 'x' || spe == 'X' || spe == 'p')
		base = 16;
	else
		base = 10;
	result = 0;
	if ((spe == 'i' || spe == 'd') && nbr < 0)
		nbr *= -1;
	temp = nbr;
	while (temp)
	{
		temp /= base;
		result++;
	}
	return (result);
}
