/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:37:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/09 20:43:47 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_play_game(char **map, t_map_data data)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		ft_error();
	win = mlx_new_window(mlx, 64 * data.x, 64 * data.y, "so_long");
	ft_create_map(map);
}
