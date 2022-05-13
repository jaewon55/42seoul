/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:31:08 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 00:09:05 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_mush(t_mlx_inst *inst)
{
	int	location[2];

	location[X] = (short)inst->p_loc;
	location[Y] = inst->p_loc >> 16;
	if (inst->key < 0)
		ft_put_img(*inst, inst->mush1, location);
	else if (inst->key == K_W)
		ft_mush_up(inst);
	else if (inst->key == K_A)
		ft_mush_left(inst);
	else if (inst->key == K_S)
		ft_mush_down(inst);
	else if (inst->key == K_D)
		ft_mush_right(inst);
}
