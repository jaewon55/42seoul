/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:08:56 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 19:21:51 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill_map(t_mlx_inst inst, char *map_line, int *location)
{
	if (*map_line == '1')
		ft_put_img(inst, inst.wall, location);
	else if (*map_line == '0')
		ft_put_img(inst, inst.space, location);
	location[X] += 64;
	return (++map_line);
}

void	ft_create_map(t_mlx_inst inst, t_map data)
{
	int		location[2];
	char	*map_line;
	int		i;

	map_line = data.map[0];
	location[Y] = 0;
	i = 1;
	while (map_line)
	{
		location[X] = 0;
		while (*map_line)
			map_line = fill_map(inst, map_line, location);
		location[Y] += 64;
		map_line = data.map[i++];
	}
}
