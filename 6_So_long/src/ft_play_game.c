/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:37:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 21:33:23 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

static int	ft_close(t_mlx_inst *inst)
{
	exit(1);
	return (1);
}

static int	ft_keyhook(int keycode, t_mlx_inst *inst)
{
	if (keycode == K_ESC)
		ft_close(inst);
	if (keycode == K_W || (keycode >= K_A && keycode <= K_D))
		ft_check_movable(keycode, inst);
	return (1);
}

void	ft_play_game(t_map data)
{
	t_mlx_inst	inst;

	if (data.x > 39 || data.y > 21)
		ft_error();
	inst.list = data.list;
	inst.p_loc = data.p_loc;
	inst.key = -1;
	inst.meso_cnt = data.c;
	inst.motion = 1;
	inst.move_cnt = 0;
	inst.map = data.map;
	inst.mlx = mlx_init();
	inst.win = mlx_new_window(inst.mlx, 64 * data.x, 64 * data.y, "so_long");
	ft_inst_img(&inst);
	ft_create_map(inst, data);
	mlx_hook(inst.win, X_DESTROY, 0, ft_close, &inst);
	mlx_key_hook(inst.win, ft_keyhook, &inst);
	mlx_loop_hook(inst.mlx, ft_loop, &inst);
	mlx_loop(inst.mlx);
}
