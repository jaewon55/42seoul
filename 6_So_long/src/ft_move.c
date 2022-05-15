/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:54:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:39:27 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_clear(t_mlx_inst *inst)
{
	printf("-----Game Clear-----\n");
	printf("move count : %d\n", inst->move_cnt);
	ft_del_map(inst->map);
	ft_del_inst(inst);
	mlx_destroy_window(inst->mlx, inst->win);
	exit(0);
}

void	ft_move(t_mlx_inst *inst)
{
	int	loc[2];

	loc[X] = (short)inst->p_loc;
	loc[Y] = inst->p_loc >> 16;
	ft_put_img(*inst, inst->space, loc);
	if (inst->key == K_W)
		loc[Y] -= 64;
	else if (inst->key == K_A)
		loc[X] -= 64;
	else if (inst->key == K_S)
		loc[Y] += 64;
	else if (inst->key == K_D)
		loc[X] += 64;
	ft_put_img(*inst, inst->mush, loc);
	inst->p_loc = loc[X] + (loc[Y] << 16);
	printf("move count\t:\t%d\n", inst->move_cnt);
	if (inst->map[loc[Y] / 64][loc[X] / 64] == 'E')
		ft_clear(inst);
	inst->key = -1;
}
