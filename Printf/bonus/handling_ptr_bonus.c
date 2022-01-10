/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:53:14 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/10 11:53:15 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
static int	write_field(ssize_t ptr, int nbr_len, int *flags)
{
	int		field_len;
	int		temp1;
	int		temp2;
	int		result;

	if (flags[WIDTH] > nbr_len + 2)
		field_len = flags[WIDTH];
	else
		field_len = nbr_len + 2;
	if (flags[MINUS_FLAG])
	{
		temp1 = write_str("0x");
		temp2 = write_nbr(ptr, 'p');
		result = write_blank(' ', field_len - (temp1 + temp2));
	}
	else
	{
		temp1 = write_blank(' ', field_len - (nbr_len + 2));
		temp2 = write_str("0x");
		result = write_nbr(ptr, 'p');
	}
	if (temp1 < 0|| temp2 < 0|| result < 0)
		return (-1);
	return (result + temp1 + temp2);
}

int	handling_ptr(const char *format, ssize_t ptr, int *flags)
{
	int		temp;
	int		result;

	temp = 0;
	result = 0;
	while (temp >= 0 && format[result] != '%')
		temp = write(1, format + (sizeof(char) * result++), 1);
	if (temp < 0)
		return (-1);
	temp = write_field(ptr, nbr_len(ptr, 'p'), flags);
	return (result + temp);
}
