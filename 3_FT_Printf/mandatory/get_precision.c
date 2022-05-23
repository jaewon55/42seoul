/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:31:44 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/11 20:06:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static size_t	ft_precision_va_arg(int *flags, va_list ap)
{
	int	precision;

	precision = va_arg(ap, int);
	if (precision < 0 || precision > INT_MAX - 1)
		flags[PRECISION] = WRONG_PRECISION;
	else if (!precision)
		flags[PRECISION] = DIGIT_ZERO;
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
	if (i == 1)
		flags[PRECISION] = DIGIT_MISSING;
	else if (!flags[PRECISION])
		flags[PRECISION] = DIGIT_ZERO;
	return (i);
}

size_t	get_precision(const char *format, int *flags, va_list ap)
{
	size_t	i;

	i = 0;
	if (format[1] == '*')
		i += ft_precision_va_arg(flags, ap);
	else
		i += ft_precision_iterator(format, flags);
	return (i);
}
