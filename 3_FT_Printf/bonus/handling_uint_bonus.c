/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:15:15 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/11 20:08:29 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static int	ft_output_len(int nbr_len, int *flags)
{
	int	result;

	result = 0;
	if (flags[POUND_KEY_FLAG])
		result = 2;
	if (nbr_len >= flags[PRECISION])
		result += nbr_len;
	else
		result += flags[PRECISION];
	return (result);
}

static int	check_pound_key_flag(char spe, int *flags)
{
	int	result;

	if (!flags[POUND_KEY_FLAG])
		return (0);
	result = write_char('0');
	result += write_char(spe);
	if (result != 2)
		return (-1);
	return (result);
}

static int	write_output(int output, unsigned int nbr, char spe, int *flags)
{
	int		result;
	int		temp;

	temp = 0;
	result = check_pound_key_flag(spe, flags);
	if (result < 0)
		return (-1);
	temp = write_blank('0', output - nbr_len(nbr, spe, flags) - result);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = 0;
	if (output)
		temp = write_nbr(nbr, spe);
	if (temp < 0)
		return (-1);
	return (result + temp);
}

static int	write_field(size_t field_len, size_t nbr, char spe, int *flags)
{
	int	result;
	int	temp;
	int	output_len;

	output_len = ft_output_len(nbr_len(nbr, spe, flags), flags);
	if (flags[MINUS_FLAG])
	{
		temp = write_output(output_len, nbr, spe, flags);
		result = write_blank(' ', field_len - output_len);
	}
	else if (flags[ZERO_FLAG] && !flags[PRECISION])
	{
		temp = check_pound_key_flag(spe, flags);
		result = write_blank('0', field_len - nbr_len(nbr, spe, flags) - temp);
		temp += write_nbr(nbr, spe);
	}
	else
	{
		temp = write_blank(' ', field_len - output_len);
		result = write_output(output_len, nbr, spe, flags);
	}
	return (result + temp);
}

int	handling_uint(const char *format, char spe, unsigned int n, int *flags)
{
	int		field_len;
	int		output_len;
	int		result;
	int		temp;

	if (!n || spe == 'u')
		flags[POUND_KEY_FLAG] = 0;
	output_len = ft_output_len(nbr_len(n, spe, flags), flags);
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
	temp = write_field(field_len, n, spe, flags);
	if (field_len != temp)
		return (-1);
	return (result + temp);
}
