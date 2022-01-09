/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:32:28 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:32:33 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
static int	output_len(int nbr, int nbr_len, int *flags)
{
	if (nbr >= 0 && nbr_len >= flags[PRECISION] \
	&& (flags[PLUS_FLAG] || flags[SPACE_FLAG]))
		return (nbr_len + 1);
	else if (nbr_len > flags[PRECISION])
		return (nbr_len);
	return (flags[PRECISION]);
}

static int	write_output(int nbr, int nbr_len, int output_len, int *flags)
{
	int		result;
	int		temp;

	temp = 0;
	if (nbr < 0)
		temp = write(1, "-", 1);
	else if (flags[PLUS_FLAG])
		temp = write(1, "+", 1);
	else if (flags[SPACE_FLAG])
		temp = write(1, " ", 1);
	if (temp < 0)
		return (-1);
	result = temp;
	temp = write_blank('0', output_len - nbr_len);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = write_nbr(nbr, 10, 'd');
	if (temp < 0)
		return (-1);
	return (result + temp);
}

static int	write_field(size_t field_len, int output_len, int nbr, int *flags)
{
	int	result;
	int	temp;

	if (flags[MINUS_FLAG])
	{
		temp = write_output(nbr, nbr_len(nbr, 'd', flags), output_len, flags);
		result = write_blank(' ', field_len - output_len);
	}
	else if (flags[ZERO] && !flags[PRECISION])
	{
		temp = write_blank('0', field_len - output_len);
		result = write_output(nbr, nbr_len(nbr, 'd', flags), output_len, flags);
	}
	else
	{
		temp = write_blank(' ', field_len - output_len);
		result = write_output(nbr, nbr_len(nbr, 'd', flags), output_len, flags);
	}
	if (temp < 0 || result < 0)
		return (-1);
	return (result + temp);
}

int	handling_int(const char *format, int nbr int *flags)
{
	size_t	field_len;
	int		result;
	int		output_len;
	int		temp;

	output_len = output_len(nbr, nbr_len(nbr, 'd', flags), flags);
	if (output_len > flags[WIDTH])
		field_len = output_len;
	else
		field_len = flags[WIDTH];
	temp = 0;
	result = 0;
	while (temp >= 0 && format[result] != '%')
		temp = write(1, format + (sizeof(char) * result++), 1);
	if (temp < 0)
		return (-1);
	temp = write_field(field_len, output_len, nbr, flags);
	if (temp < 0)
		return (-1);
	return (result + temp);
}
