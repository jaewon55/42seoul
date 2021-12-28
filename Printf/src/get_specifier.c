/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:13:32 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/28 21:13:33 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf"
char	get_specifier(char *format, char *flags)
{
	size_t	i;

	i = 1;
	while (!ft_strchr("cspdiuxX%", format[i]))
	{
		format[i]
	}
}
