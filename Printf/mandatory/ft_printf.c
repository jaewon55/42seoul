/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:54:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/27 02:50:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static int	f_len(const char *start)
{
	size_t	i;

	i = 1;
	while (start[i] && !ft_strchr("cspdiuxX%", start[i]))
		i++;
	return (sizeof(char) * i);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	int			result;

	result = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] && result >= 0)
	{
		if (format[i] == '%')
		{
			handling_conversion(format, ap, &result);
			format += (f_len(&format[i]) + (sizeof(char) * i) + sizeof(char));
			i = 0;
			continue ;
		}
		i++;
	}
	if (result >= 0)
		ft_putnstr(format, i, &result);
	va_end(ap);
	return (result);
}
