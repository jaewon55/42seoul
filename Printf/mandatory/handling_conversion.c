/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:41:00 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 18:41:02 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static int	write_specifier(char spe, va_list ap)
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

void	handling_conversion(const char *format, va_list ap, int *n, size_t i)
{
	char	*specifier;
	int		temp1;
	int		temp2;

	temp1 = 0;
	temp2 = 0;
	while (temp1 >= 0 && temp2 < i)
		temp1 = write(1, format + (sizeof(char) * temp2++), 1);
	if (temp1 < 0)
	{
		*n = -1;
		return ;
	}
	temp1 = write_specifier(format, *specifier, ap);
	if (temp1 < 0)
		*n = -1;
	else
		*n += (temp1 + temp2);
}