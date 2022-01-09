/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_conversion_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:32:15 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:32:22 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
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

static int	ft_no_optional(char spe, va_list ap)
{
	int	temp;

	if (spe == 'd' || spe == 'i' || spe == 'u')
		return (write_nbr(va_arg(ap, int), 10, spe));
	else if (spe == 'x' || spe 'X')
		return (write_nbr(va_arg(ap, int), 16, spe));
	else if (spe == 'c')
		return (write_char(va_arg(ap, int)));
	else if (spe == 's')
		return (write_char(va_arg(ap, char *)));
	else if (spe == '%')
		return (write_char('%'));
	temp = write(1, "0x", 2);
	if (temp < 0)
		return (temp);
	temp = write_nbr((ssize_t)va_arg(ap, void *), 16, spe);
	if (temp < 0)
		return (temp);
	return (temp + 2);
}

static int	ft_optional(const char *format, char spe, va_list ap, int *flags)
{
	if (check_error(spe, flags) < 0)
		return (-1);
	else if (spe == 'u' || spe == 'x' || spe == 'X')
		return (handling_uint(format, spe, va_arg(ap, int), flags));
	else if (spe == 'd' || spe == 'i')
		return (handling_int(format, spe, va_arg(ap, int), flags));
	else if (spe == 'c' || spe == '%')
		return (handling_char(format, spe, ap, flags));
	else if (spe == 'p')
		return (handling_ptr(format, (ssize_t)va_arg(ap, void *), flags));
	return (handling_str(format, va_arg(ap, char *), flags));
}

void	handling_conversion(const char *format, va_list ap, int *n, size_t i)
{
	char	*specifier;
	int		flags[7];
	int		temp1;
	int		temp2;

	specifier = get_specifier(&format[i], flags, ap);
	temp1 = 0;
	temp2 = 0;
	if (specifier == &format[i] + sizeof(char))
	{
		while (temp1 >= 0 && format[temp2] != '%')
			temp1 = write(1, format + (sizeof(char) * temp2++), 1);
		if (temp1 < 0)
		{
			*n = -1;
			return ;
		}
		temp1 = ft_no_optional(format, *specifier, ap);
	}
	else
		temp1 = ft_optional(format, *specifier, ap, flags);
	if (temp1 < 0)
		*n = -1;
	else
		*n += (temp1 + temp2);
}
