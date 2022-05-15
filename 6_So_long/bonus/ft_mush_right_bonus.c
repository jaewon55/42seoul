/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mush_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:58:59 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:56:12 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

static void	ft_repair_above(t_mlx_inst *inst, int x, int y)
{
	void	*fix_img1;
	void	*fix_img2;
	int		loc[2];

	fix_img1 = NULL;
	fix_img2 = NULL;
	if (inst->map[y][x] == '1')
		fix_img1 = inst->wall;
	else if (inst->map[y][x] == '0')
		fix_img1 = inst->space;
	else if (inst->map[y][x] == 'X')
		fix_img1 = inst->enemy;
	if (inst->map[y][x + 1] == '1')
		fix_img2 = inst->wall;
	else if (inst->map[y][x + 1] == '0')
		fix_img2 = inst->space;
	else if (inst->map[y][x + 1] == 'X')
		fix_img2 = inst->enemy;
	loc[X] = x * 64;
	loc[Y] = y * 64;
	ft_put_img(*inst, fix_img1, loc);
	loc[X] += 64;
	ft_put_img(*inst, fix_img2, loc);
}

static void	ft_jump_motion(t_mlx_inst *inst, int *loc)
{
	if (inst->motion != 3)
		ft_repair_above(inst, loc[X] / 64, loc[Y] / 64 - 1);
	ft_put_img(*inst, inst->space, loc);
	inst->p_loc += 16;
	loc[X] = (short)inst->p_loc;
	loc[Y] -= 16;
	ft_put_img(*inst, inst->mush4, loc);
	inst->motion++;
}

static void	ft_put_motion(t_mlx_inst *inst, void *img, int *loc)
{
	if (inst->motion == 7)
		ft_repair_above(inst, loc[X] / 64, loc[Y] / 64 - 1);
	ft_put_img(*inst, inst->space, loc);
	ft_put_img(*inst, img, loc);
	if (inst->motion++ == 8)
	{
		inst->motion = 1;
		inst->key = -1;
		printf("move count\t:\t%d\n", inst->move_cnt);
		if (inst->map[loc[Y] / 64][loc[X] / 64] == 'X')
			inst->key = DEAD;
		if (inst->map[loc[Y] / 64][loc[X] / 64] == 'E')
			inst->key = CLEAR;
	}
}

void	ft_mush_right(t_mlx_inst *inst, int *loc)
{
	if (inst->motion == 1)
		ft_put_motion(inst, inst->mush2, loc);
	else if (inst->motion == 2)
		ft_put_motion(inst, inst->mush3, loc);
	else if (inst->motion == 3)
		ft_jump_motion(inst, loc);
	else if (inst->motion == 4)
		ft_jump_motion(inst, loc);
	else if (inst->motion == 5)
		ft_jump_motion(inst, loc);
	else if (inst->motion == 6)
		ft_jump_motion(inst, loc);
	else if (inst->motion == 7)
		ft_put_motion(inst, inst->mush2, loc);
	else if (inst->motion == 8)
		ft_put_motion(inst, inst->mush1, loc);
}
