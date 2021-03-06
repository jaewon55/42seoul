/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:59:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:35:20 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	ft_check_wall(char	**map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (map[++i])
		if (map[i][0] != '1')
			ft_error("The map must be closed/surrounded by walls\n");
	len = -1;
	while (map[0][++len])
		if (map[0][len] != '1' || map[i - 1][len] != '1')
			ft_error("The map must be closed/surrounded by walls\n");
	j = 0;
	while (map[++j])
		if (map[j][len - 1] != '1')
			ft_error("The map must be closed/surrounded by walls\n");
	return (len);
}

static void	ft_check_element(char c, t_map *map_data, int x, int y)
{
	if (c == 'P')
		map_data->p++;
	else if (c == 'E')
		map_data->e++;
	else if (c == 'C')
		map_data->c++;
	else if (c != '0' && c != '1')
		ft_error("The map must be composed of only 5 possible characters\n");
	if (map_data->p > 1)
		ft_error("Too many starting position\n");
	else if (c == 'P')
	{
		map_data->p_loc = y * 64;
		map_data->p_loc <<= 16;
		map_data->p_loc += x * 64;
	}
}

t_map	ft_check_map(char **map)
{
	t_map	map_data;
	int		len;
	int		i;
	int		j;

	ft_memset(&map_data, 0, sizeof(t_map));
	len = ft_check_wall(map);
	map_data.map = map;
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
			ft_check_element(map[i][j], &map_data, j, i);
		if (len != j)
			ft_error("The map must be rectangular\n");
	}
	if (!map_data.c || !map_data.e || !map_data.p)
		ft_error("The map must have at least one E, one C, and one P\n");
	map_data.x = j;
	map_data.y = i;
	return (map_data);
}
