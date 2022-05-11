/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:08:56 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/11 16:29:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill_map(t_mlx_instance instance, char *map_line, int *location)
{
	if (*map_line == '1')
		ft_put_img(instance, WALL, location);
	else if (*map_line == 'E')
		ft_put_img(instance, ESCAPE_C, location);
	else
		ft_put_img(instance, SPACE, location);
	if (*map_line == 'C')
		ft_put_img(instance, MESO, location);
	else if (*map_line == 'P')
		ft_put_img(instance, PLAYER, location);
	location[X] += 64;
	return (++map_line);
}

void	ft_create_map(t_mlx_instance instance, t_map_data data)
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
			map_line = fill_map(instance, map_line, location);
		location[Y] += 64;
		map_line = data.map[i++];
	}
}
