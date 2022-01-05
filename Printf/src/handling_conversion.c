/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:03:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/28 21:03:48 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static size_t get_precision(const char *format, int *flags, va_list ap)
{
	size_t	i;
	int	precision;

	i = 1;
	precision = 0;
	while (format[i] && !ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == '*')
		{
			precision = va_arg(ap, int);
			i++;
			break ;
		}
		precision *= 10;
		precision += (format[i] - '0');
		i++;
	}
	if (!precision)
		precision = -1;
	flags[6] = precision;
	return (i);
}

static size_t get_width(const char *format, int *flags, va_list ap)
{
	size_t		i;
	long long	width;

	i = 0;
	width = 0;
	while (format[i] && !ft_strchr(".cspdiuxX%", format[i]))
	{
		if (format[i] == '*')
		{
			width = va_arg(ap, int);
			if (width < 0)
				width *= -1;
			i++;
			break;
		}
		width *= 10;
		width += (format[i] - '0');
		i++;
	}
	flags[5] = width;
	if (format[i] == '.')
		i += get_precision(&format[i], flags, ap);
	return (i);
}

static char	get_specifier(const char *format, int *flags, va_list ap)
{
	size_t	i;

	ft_bzero(flags, sizeof(int) * 7);
	i = 1;
	while (format[i] && !ft_strchr("cspdiuxX%.*123456789", format[i]))
	{
		if (format[i] == '-')
			flags[0] = 1;
		else if (format[i] == '+')
			flags[1] = 1;
		else if (format[i] == ' ')
			flags[2] = 1;
		else if (format[i] == '#')
			flags[3] = 1;
		else if (format[i] == '0')
			flags[4] = 1;
		i++;
	}
	if (ft_strchr("*123456789", format[i]))
		i += get_width(&format[i], flags, ap);
	else if (format[i] == '.')
		i += get_precision(&format[i], flags, ap);
	return (format[i]);
}

void	handling_conversion(const char *format, va_list ap, int *n, size_t i)
{
	char	specifier;
	int	flags[7];
	int	temp;

	specifier = get_specifier(&format[i], flags, ap);
	// if (specifier == 'd' || specifier == 'i')
		temp = handling_int(flags, ap, format, i);
	if (temp < 0)
		*n = -1;
	else
		*n += temp;
}
