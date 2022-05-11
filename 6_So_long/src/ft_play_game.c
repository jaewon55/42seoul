/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:37:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/11 18:22:22 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static int	ft_close(t_mlx_instance *instance)
{
	exit(0);
	return (1);
}

static int	ft_keyhook(int keycode, t_mlx_instance *instance)
{
	if (keycode == K_ESC)
		ft_close(instance);
	return (1);
}

void	ft_play_game(t_map_data data)
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
	mlx_hook(instance.win, X_DESTROY, 0, ft_close, &instance);
	mlx_key_hook(instance.win, ft_keyhook, &instance);
	mlx_loop(instance.mlx);
}
