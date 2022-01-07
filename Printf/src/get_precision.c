/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:26:04 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/06 13:26:05 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static size_t	ft_precision_va_arg(const char *format, int *flags, va_list ap)
{
	int	precision;

	precision = va_arg(ap, int);
	if (precision < 0 || precision > INT_MAX - 1)
		flags[PRECISION] = -1;
	else
		flags[PRECISION] = precision;
	return (1);
}

static size_t	ft_precision_iterator(const char *format, int *flags)
{
	size_t	i;

	i = 1;
	while (format[i] && !ft_strchr("cspdiuxX%", format[i]))
	{
		flags[PRECISION] *= 10;
		flags[PRECISION] += (format[i] - '0');
		i++;
	}
	if (i = 1)
		flags[PRECISION] = 1;
	return (i);
}

size_t get_precision(const char *format, int *flags, va_list ap)
{
	size_t i;

	i = 1;
	if (format[i] == '*')
		i += ft_precision_va_arg(format, flags, ap);
	else
		i += ft_precision_iterator(format, flags);
	return (i);
}
