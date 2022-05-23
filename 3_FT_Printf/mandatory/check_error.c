/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:30:03 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/13 16:58:13 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	check_error(int *flags)
{
	if (flags[PRECISION] == WRONG_PRECISION || flags[WIDTH] < 0)
		return (-1);
	return (1);
}
