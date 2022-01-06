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
static char	*get_specifier(const char *format, int *flags, va_list ap)
{
	size_t	i;

	ft_bzero(flags, sizeof(int) * 7);
	i = 1;
	while (format[i] && !ft_strchr("cspdiuxX%.*123456789", format[i]))
	{
		if (format[i] == '-')
			flags[MINUS_FLAG] = 1;
		else if (format[i] == '+')
			flags[PLUS_FLAG] = 1;
		else if (format[i] == ' ')
			flags[SPACE_FLAG] = 1;
		else if (format[i] == '#')
			flags[POUND_KEY_FLAG] = 1;
		else if (format[i] == '0')
			flags[ZERO_FLAG] = 1;
		i++;
	}
	if (ft_strchr("*123456789", format[i]))
		i += get_width(&format[i], flags, ap);
	else if (format[i] == '.')
		i += get_precision(&format[i], flags, ap);
	return (&format[i]);
}

static int	ft_no_optional(const char *format, char spe, va_list ap)
{

}

static int	ft_optional(const char *format, char spe, va_list ap, int *flags)
{
	if (spe == 'u' || spe == 'x' || spe == 'X')
		return (handling_uint());
	else if (spe == 'd' || spe == 'i')
		return (handling_int());
	else if (spe == 'c' || spe == '%')
		return (handling_char());
	else if (spe == 'p')
		return (handling_ptr());
	else
		return (handling_str());
}

void	handling_conversion(const char *format, va_list ap, int *n, size_t i)
{
	char	*specifier;
	int		flags[7];
	int		temp;

	specifier = get_specifier(&format[i], flags, ap);
	if (specifier == &format[i] + sizeof(char))
		temp = ft_no_optional(format, *specifier, ap);
	else
		temp = ft_optional(format, *specifier, ap, flags);
	if (temp < 0)
		*n = -1;
	else
		*n += temp;
}
