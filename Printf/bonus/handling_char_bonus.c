/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:21:59 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 20:22:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.c"
int	handling_char(const char *format, char spe, va_list ap, int *flags)
{
	size_t	field_len;

	field_len = 1;
	if (flags[WIDTH])
		field_len = flags[WIDTH];
	if (flags[MINUS])
	{

	}
	else if (spe == %)
	write_blank('')
}
