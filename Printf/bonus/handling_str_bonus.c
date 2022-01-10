/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:32:50 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/10 13:32:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
static int	ft_output_len(int str_len, int *flags)
{
	if (!flags[PRECISION])
		return (str_len);
	else if (flags[PRECISION] < 0)
		return (0);
	else if (flags[PRECISION] > str_len)
		return (flags[PRECISION]);
	return (str_len);
}

static int	write_output(char *str, size_t output_len)
{
	size_t	i;
	int		temp;

	i = 0;
	while (i < output_len)
	{
		temp = write_char(str[i]);
		if (temp < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	write_field(char *str, int output_len, int *flags)
{
	int		field_len;
	int		temp;
	int		result;

	if (flags[WIDTH] > output_len)
		field_len = flags[WIDTH];
	else
		field_len = output_len;
	if (flags[MINUS_FLAG])
	{
		temp = write_output(str, output_len);
		result = write_blank(' ', field_len - output_len);
	}
	else
	{
		temp = write_blank(' ', field_len - output_len);
		result = write_output(str, output_len);
	}
	if (temp < 0 || result < 0)
		return (-1);
	return (temp + result);
}

int	handling_str(const char *format, char *str, int *flags)
{
	int		output_len;
	int		temp;
	int		result;

	if (!str)
		str = "(null)";
	output_len = ft_output_len(ft_strlen(str), flags);
	temp = 0;
	result = 0;
	while (temp >= 0 && format[result] != '%')
		temp = write(1, format + (sizeof(char) * result++), 1);
	if (temp < 0)
		return (-1);
	temp = write_field(str, output_len, flags);
	if (temp < 0)
		return (-1);
	return (temp + result);
}
