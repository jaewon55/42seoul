/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:57:59 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 02:14:22 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = malloc(size * count);
	if (!result)
		return (0);
	i = 0;
	while (i < (size * count))
	{
		((unsigned char *)result)[i] = 0;
		i++;
	}
	return (result);
}
