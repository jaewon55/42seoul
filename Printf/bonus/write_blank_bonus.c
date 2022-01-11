/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_blank_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:48:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:33:17 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
int	write_blank(char blank, int n)
{
	int	result;
	int	temp;

	result = 0;
	while (result > -1 && n > 0)
	{
		temp = write(1, &blank, 1);
		if (temp < 0)
			return (-1);
		n--;
		result++;
	}
	return (result);
}
