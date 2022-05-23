/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:21:59 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 20:22:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	write_field(size_t field_len, char c, int *flags)
{
	int		temp;
	int		result;

	if (flags[MINUS_FLAG])
	{
		temp = write_char(c);
		result = write_blank(' ', field_len - 1);
	}
	else if (flags[ZERO_FLAG])
	{
		temp = write_blank('0', field_len - 1);
		result = write_char(c);
	}
	else
	{
		temp = write_blank(' ', field_len - 1);
		result = write_char(c);
	}
	if (temp < 0 || result < 0)
		return (-1);
	return (temp + result);
}

int	handling_char(const char *format, char spe, va_list ap, int *flags)
{
	size_t	field_len;
	char	c;
	int		temp;
	int		result;

	if (spe != '%')
		c = va_arg(ap, int);
	else
		c = '%';
	field_len = 1;
	if (flags[WIDTH])
		field_len = flags[WIDTH];
	temp = 0;
	result = 0;
	while (temp >= 0 && format[result] != '%')
		temp = write(1, format + (sizeof(char) * result++), 1);
	if (temp < 0)
		return (-1);
	temp = write_field(field_len, c, flags);
	if (temp < 0)
		return (-1);
	return (result + temp);
}
