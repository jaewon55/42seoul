/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:15:15 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:32:44 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libftprintf_bonus.h"
static int	output_len(int nbr_len, int *flgas)
{
	if (flags[POUND_KEY_FLAG])
		nbr_len += 2;
	if (nbr_len >= flgas[PRECISION])
		return (nbr_len);
	return (flgas[PRECISION]);
}

static int	write_output(unsigned int nbr, int nbr_len, char spe, int *flags)
{
	int		result;
	int		temp;

	result = 0;
	temp = 0;
	if (flgas[POUND_KEY_FLAG])
	{
		temp = write_char('0');
		result = write_char(spe);
	}
	if (temp < 0 || result < 0)
		return (-1);
	result += temp;
	temp = write_blank('0', flags[PRECISION] - nbr_len);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = write_nbr(nbr, 16, spe);
	if (temp < 0)
		return (-1);
	return (result + temp);
}

static int	write_field(size_t field_len, int nbr, char spe, int *flags)
{
	int	result;
	int	temp;

	temp = 0;
	if (flags[MINUS_FLAG])
	{
		temp = write_output(nbr, nbr_len(nbr, spe, flags), spe, flags);
		result = write_blank(' ', field_len - output_len);
	}
	else if (flags[ZERO] && !flags[PRECISION])
	{
		if (flags[POUND_KEY_FLAG])
			flags[PRECISION] = field_len - 2;
		else
			flags[PRECISION] = field_len;
		result = write_output(nbr, nbr_len(nbr, spe, flags), spe, flags);
	}
	else
	{
		temp = write_blank(' ', field_len - output_len);
		result = write_output(nbr, nbr_len(nbr, spe, flags), spe, flags);
	}
	if (temp < 0 || result < 0)
		return (-1);
	return (result + temp);
}

int	handling_uint(const char *format, char spe, unsigned int n, int *flgas)
{
	size_t	field_len;
	int		output_len;
	int		result;
	int		temp;

	if (!n || spe == 'u')
		flags[POUND_KEY_FLAG] = 0;
	output_len = output_len(nbr_len(n, spe, flgas), flgas);
	if (output_len > flgas[WIDTH])
		field_len = output_len;
	else
		field_len = flgas[WIDTH];
	temp = 0;
	result = 0;
	while (temp >= 0 && format[result] != '%')
		temp = write(1, format + (sizeof(char) * result++), 1);
	if (temp < 0)
		return (-1);
	temp = write_field(field_len, n, spe, flags);
	if (temp < 0)
		return (-1);
	return (result + temp);
}
