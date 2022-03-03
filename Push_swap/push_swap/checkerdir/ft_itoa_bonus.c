/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:29:46 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 18:29:46 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static char	*num_start_point(char *str, int *minus)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		*minus = -1;
	}
	if (!str[i] || !(str[i] >= '0' && str[i] <= '9'))
		return (NULL);
	return (&str[i]);
}

ssize_t	ft_itoa(char **str)
{
	int		minus;
	int		i;
	ssize_t	n;

	minus = 1;
	*str = num_start_point(*str, &minus);
	if (!(*str))
		return (UINT_MAX);
	i = 0;
	n = 0;
	while ((*str)[i] && (*str)[i] >= '0' && (*str)[i] <= '9')
	{
		n *= 10;
		n += (*str)[i++] - '0';
	}
	if ((minus < 0 && n > (ssize_t)INT_MAX + 1) || (minus > 0 && n > INT_MAX))
		return (UINT_MAX);
	*str = &((*str)[i]);
	return (n);
}
