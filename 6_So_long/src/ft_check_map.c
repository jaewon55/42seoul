/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:59:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/11 19:29:49 by jaewchoi         ###   ########.fr       */
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

static void	ft_check_element(char c, t_map_data *map_data)
{
	if (c == 'P')
		map_data->p++;
	else if (c == 'E')
		map_data->e++;
	else if (c == 'C')
		map_data->c++;
	else if (c != '0' && c != '1')
		ft_error();
}

t_map_data ft_check_map(char **map)
{
	t_map_data	map_data;
	int			len;
	int			i;
	int			j;

	ft_memset(&map_data, 0, sizeof(t_map_data));
	len = ft_check_wall(map);
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
			ft_check_element(map[i][j], &map_data);
		if (len != j)
			ft_error();
	}
	if (!map_data.c || !map_data.e || map_data.p != 1)
		ft_error();
	map_data.x = j;
	map_data.y = i;
	return (map_data);
}

