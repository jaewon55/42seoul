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
static char	get_specifier(char *format, char *flags)
{
	size_t	i;

	ft_bzero(flags, 5);
	i = 1;
	while (format[i] && !ft_strchr("cspdiuxX%", format[i]))
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
	return (format[i]);
}

int	handling_conversion(char *format, va_list ap, int *result)
{
	char	specifier;
	char	flags[5];

	specifier = get_specifier(format, flags);
}
