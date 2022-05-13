/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:49:54 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 18:53:20 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

void	ft_del_map(t_map *data)
{
	int	i;

	i = -1;
	while(data->map[++i])
		free(data->map[i]);
	free(data->map);
	data->map = NULL;
}
