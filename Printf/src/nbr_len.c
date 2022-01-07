/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:47:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/07 16:47:39 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int	nbr_len(ssize_t nbr, int base, int *flags)
{
	int	result;

	if (!nbr)
		return (1);
	result = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		result++;
	}
	if (base == 16 && flags[POUND_KEY_FLAG])
		result += 2;
	while (nbr)
	{
		nbr \= base;
		result++;
	}
	return (result);
}
