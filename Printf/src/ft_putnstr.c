/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:05:14 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/30 01:05:15 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
void	ft_putnstr(char *str, size_t n, int *result)
{
	if (!str || !n)
		return ;
	if (write(1, str, n) < 0)
		result = -1;
	else
		result += n;
}
