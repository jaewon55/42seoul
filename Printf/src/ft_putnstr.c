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
int	ft_putnstr(const char *str, size_t n)
{
	if (!str || !n)
		return (0);
	if (write(1, str, n) < 0)
		return (-1);
	else
		return (n);
}
