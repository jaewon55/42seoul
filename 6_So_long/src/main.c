/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:11:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/09 01:55:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main(int ac, char **av)
{
	char		**map;
	t_map_data	map_data;

	if (ac != 2)
		ft_error();
	map = ft_parse_map(av[1]);
	map_data = ft_check_map(map);
	return (0);
}
