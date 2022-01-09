/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:30:03 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:31:26 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
int	check_error(int *flags)
{
	if (flags[PRECISION] == WRONG_PRECISION || flags[WIDTH] < 0)
		return (-1);
	return (1);
}
