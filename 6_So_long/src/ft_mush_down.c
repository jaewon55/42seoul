/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mush_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:03:11 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 19:57:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_jump_motion(t_mlx_inst *inst, int *loc)
{
	ft_put_img(*inst, inst->space, loc);
	inst->p_loc += 16 << 16;
	loc[X] = (short)inst->p_loc;
	loc[Y] += 16;
	ft_put_img(*inst, inst->mush4, loc);
	inst->motion++;
}

static void	ft_put_motion(t_mlx_inst *inst, void *img, int *loc)
{
	ft_put_img(*inst, inst->space, loc);
	ft_put_img(*inst, img, loc);
	if (inst->motion++ == 8)
	{
		inst->motion = 1;
		inst->key = -1;
		if (inst->map[loc[Y] / 64][loc[X] / 64] == 'X')
			inst->key = DEAD;
		if (inst->map[loc[Y] / 64][loc[X] / 64] == 'E')
			inst->key = CLEAR;
	}
}

void	ft_mush_down(t_mlx_inst *inst, int *loc)
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
