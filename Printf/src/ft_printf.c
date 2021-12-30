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
static int	get_flag_len(char *start)
{
	size_t	i;

	i = 1;
	while (start[i] && !ft_strchr("cspdiuxX%", start[i]))
		i++;
	return (i + 1);
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
			ft_putnstr(format, i, *result);
			handling_conversion(&format[i], ap, *result);
			format += get_flag_len(&format[i]);
			i = 0;
			continue ;
		}
		i++;
	}
	if (result >= 0)
		ft_putnstr(format, i, *result);
	va_end(ap);
	free(temp);
	return (result);
}
