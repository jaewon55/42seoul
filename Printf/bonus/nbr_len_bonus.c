/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:33:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:33:09 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
int	nbr_len(ssize_t nbr, char spe)
{
	int		result;
	int		base;

	if (spe == 'x' || spe == 'X' || spe == 'p')
		base = 16;
	else
		base = 10;
	if (!nbr)
		return (1);
	result = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		result++;
	}
	while (nbr)
	{
		nbr /= base;
		result++;
	}
	return (result);
}
