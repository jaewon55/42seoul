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
size_t	ft_putnstr(char *str, size_t n)
{
	if (!str || !n)
		return (0);
	write(1, str, n);
	return (n);
}
