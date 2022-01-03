/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:35:09 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/01 21:35:10 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static char	*real_print_nbr(char *nbr, int modifier)
{
	char	*result;
	int	len;
	int	nbr_len;

	if (!modifier)
		return (nbr);
	nbr_len = ft_strlen(nbr)
	if (nbr_len > modifier)
		len = nbr_len;
	else
		len = modifier;
	result = (char *)ft_calloc(len + 1, sizeof(char)));
	if (!result)
	{
		free(nbr);
		return (NULL);
	}
	while (nbr_len > 0)
		result[len--] = nbr[nbr_len--];
	if (nbr[0] != '-')
		result[len] = nbr[nbr_len];
	free(nbr);
	return (result);
}

static char	*apply_modifier(char *nbr, int *flags)
{
	char	*result;
	int	nbr_len;
	int	i;
	char	tmp;

	if (!nbr)
		return (NULL);
	nbr_len = ft_strlen(nbr);
	temp = nbr[0];
	result = real_print_nbr(nbr, flags[6]);
	if (!result)
		return (NULL);
	i = 0;
	if (temp == '-')
		result[i++] = '-';
	else if (flags[1])
		result[i++] = '+';
	else if (flags[2])
		result[i++] = ' ';
	while (i < (flags[6] - nbr_len))
		result[i++] = '0';
	return (result);
}

char	*handling_int(char specifier, int *flags, va_list ap)
{
	char	*write_nbr

	write_nbr = apply_modifier(ft_itoa(va_arg(ap, int)), flags);
	if (!write_nbr)
		return (NULL);
	
}
