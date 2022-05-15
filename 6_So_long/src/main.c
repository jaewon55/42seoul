/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:08:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:49:45 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	t_map	map_data;

	if (ac != 2 || !ft_check_map_file_extension(av[1]))
		ft_error("please check mapfile name\n");
	map = ft_parse_map(av[1]);
	map_data = ft_check_map(map);
	map_data.map = map;
	ft_play_game(map_data);
	return (1);
}
