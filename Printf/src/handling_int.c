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
static int	get_len(char *nbr, int nbr_len, int *flags)
{
	if (nbr[0] != '-' && nbr_len >= flags[6] && (flags[1] || flags[2]))
		return (nbr_len + 1);
	else if (nbr_len > flags[6])
		return (nbr_len);
	return (flags[6]);
}

static char	*malloc_and_fill_nbr(char *nbr, int *flags)
{
	char	*result;
	int	len;
	int	nbr_len;

	if (flags[6] <= 0)
		return (nbr);
	nbr_len = ft_strlen(nbr);
	len = get_len(nbr, nbr_len, flags);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
	{
		free(nbr);
		return (NULL);
	}
	while (nbr_len > 1)
		result[--len] = nbr[--nbr_len];
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
	char	temp;

	if (!nbr)
		return (NULL);
	nbr_len = ft_strlen(nbr);
	temp = nbr[0];
	result = malloc_and_fill_nbr(nbr, flags);
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
	return (get_field(result, flags));
}

int	handling_int(int *flags, va_list ap, const char *format, size_t i)
{
	char	*field;
	int	result;

	field = apply_modifier(ft_itoa(va_arg(ap, int)), flags);
	if (!field)
		return (-1);
	result = ft_putnstr(format, i);
	if (result < 0 || write(1, field, ft_strlen(field)) < 0)
		result = -1;
	else
		result += ft_strlen(field);
	free(field);
	return (result);
}
