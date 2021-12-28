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
void	handling_conversion(char *format, va_list ap, int *result)
{
	char	specifier;
	char	flags[7];

	specifier = get_specifier(format, flags);
}
