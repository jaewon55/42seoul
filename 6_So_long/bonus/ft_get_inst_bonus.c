/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inst_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:49:26 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:21:32 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

t_mlx_inst	ft_get_inst_b(t_map map_data)
{
	t_mlx_inst	inst;
	int			x;
	int			y;

	x = map_data.x;
	y = map_data.y;
	inst.list = map_data.list;
	inst.p_loc = map_data.p_loc;
	inst.key = -1;
	inst.meso_cnt = map_data.c;
	inst.motion = 1;
	inst.cnt_loc = map_data.y * 64 - 38;
	inst.move_cnt = 0;
	inst.map = map_data.map;
	inst.mlx = mlx_init();
	inst.win = mlx_new_window(inst.mlx, 64 * x, 64 * y, "so_long_bonus");
	ft_inst_img_b(&inst);
	return (inst);
}
