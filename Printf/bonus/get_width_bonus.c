/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:32:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:32:10 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
static size_t	ft_width_va_arg(const char *format, int *flags, va_list ap)
{
	long long	width;

	width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		flags[MINUS_FLAG] = 1;
	}
	if (width > INT_MAX - 1)
		flags[WIDTH] = -1;
	return (1);
}

static size_t	ft_width_iterator(const char *format, int *flags)
{
	size_t	i;

	i = 0;
	while (format[i] && !ft_strchr(".cspdiuxX%", format[i]))
	{
		flags[WIDTH] *= 10;
		flags[WIDTH] += (format[i] - '0');
		i++;
	}
	return (i);
}

size_t get_width(const char *format, int *flags, va_list ap)
{
	size_t	i;

	if (format[0] == '*')
		i = ft_width_va_arg(format, flags, ap);
	else
		i = ft_width_iterator(format, flags);
	if (format[i] == '.')
		i += get_precision(&format[i], flags, ap);
	return (i);
}
