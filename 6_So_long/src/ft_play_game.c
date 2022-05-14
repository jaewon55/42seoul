/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:37:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 02:05:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static int	ft_close(t_mlx_inst *inst)
{
	ft_del_map(inst->map);
	ft_del_inst(inst);
	mlx_destroy_window(inst->mlx, inst->win);
	exit(0);
	return (1);
}

static int	ft_keyhook(int keycode, t_mlx_inst *inst)
{
	if (keycode == K_ESC)
		ft_close(inst);
	if (inst->key >= DEAD && inst->motion > 6 && keycode == K_SPACE)
		ft_close(inst);
	if (inst->key >= 0)
		return (1);
	if (keycode == K_W || (keycode >= K_A && keycode <= K_D))
		ft_check_movable(keycode, inst);
	return (1);
}

void	ft_play_game(t_map map_data)
{
	t_mlx_inst	inst;

	if (map_data.x > 39 || map_data.y > 21)
		ft_error();
	inst = ft_get_inst(map_data);
	ft_create_map(inst, map_data);
	mlx_hook(inst.win, X_DESTROY, 0, ft_close, &inst);
	mlx_key_hook(inst.win, ft_keyhook, &inst);
	mlx_loop_hook(inst.mlx, ft_loop, &inst);
	mlx_loop(inst.mlx);
}
