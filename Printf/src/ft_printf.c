/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:54:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/19 17:54:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int	ft_printf(const char *format, ...)
{
	va_list		ap
	size_t		i;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
	}
}
