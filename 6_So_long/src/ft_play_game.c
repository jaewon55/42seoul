/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:37:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/10 22:04:32 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_play_game(char **map, t_map_data data)
{
	t_mlx_instance	instance;

	if (data.x > 39 || data.y > 21)
		ft_error();
	instance.mlx = mlx_init();
	if (!instance.mlx)
		ft_error();
	instance.win = mlx_new_window\
	(instance.mlx, 64 * data.x, 64 * data.y, "so_long");
	if (!instance.win)
		ft_error();
	ft_create_map(instance, data);
	mlx_loop(instance.mlx);
}
