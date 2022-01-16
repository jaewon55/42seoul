/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:06:05 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/10 15:06:06 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
void	ft_putnstr(const char *format, size_t i, int *result)
{
	int	temp;

	temp = (write(1, format, i));
	if (temp < 0)
		*result = -1;
	else
		*result += temp;
}
