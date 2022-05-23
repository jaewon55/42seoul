/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:32:28 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:32:33 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	ft_output_len(int nbr, int nbr_len, int *flags)
{
	int	temp;

	if ((nbr >= 0 && (flags[PLUS_FLAG] || flags[SPACE_FLAG])) || (nbr < 0))
		temp = 1;
	else
		temp = 0;
	if (flags[PRECISION] >= nbr_len)
		return (flags[PRECISION] + temp);
	return (nbr_len + temp);
}

static int	write_output(ssize_t nbr, int nbr_len, int output, int *flags)
{
	int		result;
	int		temp;

	temp = 0;
	if (nbr < 0)
	{
		temp = write(1, "-", 1);
		nbr *= -1;
	}
	else if (flags[PLUS_FLAG])
		temp = write(1, "+", 1);
	else if (flags[SPACE_FLAG])
		temp = write(1, " ", 1);
	if (temp < 0)
		return (-1);
	result = temp;
	temp = write_blank('0', output - (nbr_len + temp));
	if (temp < 0)
		return (-1);
	result += temp;
	temp = 0;
	if (output)
		temp = write_nbr(nbr, 'd');
	return (result + temp);
}

static int	write_field(int field, int output, size_t nbr, int *flags)
{
	int	result;
	int	temp;

	if (flags[MINUS_FLAG])
	{
		temp = write_output(nbr, nbr_len(nbr, 'd', flags), output, flags);
		result = write_blank(' ', field - output);
	}
	else if (flags[ZERO_FLAG] && !flags[PRECISION])
	{
		temp = 0;
		result = write_output(nbr, nbr_len(nbr, 'd', flags), field, flags);
	}
	else
	{
		temp = write_blank(' ', field - output);
		result = write_output(nbr, nbr_len(nbr, 'd', flags), output, flags);
	}
	if (temp < 0 || result < 0)
		return (-1);
	return (result + temp);
}

int	handling_int(const char *format, int nbr, int *flags)
{
	int		field_len;
	int		result;
	int		output_len;
	int		temp;

	output_len = ft_output_len(nbr, nbr_len(nbr, 'd', flags), flags);
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
	if (field_len != temp)
		return (-1);
	return (result + temp);
}
