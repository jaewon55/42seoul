/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:59:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 17:49:56 by jaewchoi         ###   ########.fr       */
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
			ft_error();
	len = -1;
	while (map[0][++len])
		if (map[0][len] != '1' || map[i - 1][len] != '1')
			ft_error();
	j = 0;
	while (map[++j])
		if (map[j][len - 1] != '1')
			ft_error();
	return (len);
}

static void	ft_linking_list(t_map *map, t_ele *new)
{
	if (!map->list)
	{
		new->next = NULL;
		new->prev = NULL;
		map->list = new;
		return ;
	}
	new->next = map->list;
	new->prev = NULL;
	map->list->prev = new;
	map->list = new;
}

static void	ft_add_list(char c, t_map *map_data, int x, int y)
{
	t_ele	*new;

	new = malloc(sizeof(t_ele));
	if (!new)
		ft_error();
	new->c = c;
	new->location = y * 64;
	new->location <<= 16;
	new->location += x * 64;
	if (c == 'C')
		new->status = 1;
	else
		new->status = 0;
	ft_linking_list(map_data, new);
}

static void	ft_check_element(char c, t_map *map_data, int x, int y)
{
	if (c == 'P')
		map_data->p++;
	else if (c == 'E')
		map_data->e++;
	else if (c == 'C')
		map_data->c++;
	else if (c != '0' && c != '1' && c != 'X')
		ft_error();
	if (map_data->p > 1)
		ft_error();
	if (c == 'E' || c == 'C')
		ft_add_list(c, map_data, x, y);
	else if (c == 'P')
	{
		map_data->map[y][x] = '0';
		map_data->p_loc = y * 64;
		map_data->p_loc <<= 16;
		map_data->p_loc += x * 64;
	}
}

t_map ft_check_map(char **map)
{
	t_map	map_data;
	int			len;
	int			i;
	int			j;

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
			ft_error();
	}
	if (!map_data.c || !map_data.e)
		ft_error();
	map_data.x = j;
	map_data.y = i;
	return (map_data);
}

