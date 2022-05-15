/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:44:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:37:33 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>

static void	ft_del_list(t_mlx_inst *inst)
{
	t_ele	*temp;
	t_ele	*del;

	temp = inst->list;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
	}
	inst->list = NULL;
}

void	ft_del_inst_b(t_mlx_inst *inst)
{
	mlx_destroy_image(inst->mlx, inst->meso1);
	mlx_destroy_image(inst->mlx, inst->meso2);
	mlx_destroy_image(inst->mlx, inst->meso3);
	mlx_destroy_image(inst->mlx, inst->meso4);
	mlx_destroy_image(inst->mlx, inst->mush1);
	mlx_destroy_image(inst->mlx, inst->mush2);
	mlx_destroy_image(inst->mlx, inst->mush3);
	mlx_destroy_image(inst->mlx, inst->mush4);
	mlx_destroy_image(inst->mlx, inst->escape1);
	mlx_destroy_image(inst->mlx, inst->escape2);
	mlx_destroy_image(inst->mlx, inst->die1);
	mlx_destroy_image(inst->mlx, inst->die2);
	mlx_destroy_image(inst->mlx, inst->die3);
	mlx_destroy_image(inst->mlx, inst->die4);
	mlx_destroy_image(inst->mlx, inst->die5);
	mlx_destroy_image(inst->mlx, inst->die6);
	mlx_destroy_image(inst->mlx, inst->enemy);
	mlx_destroy_image(inst->mlx, inst->space);
	mlx_destroy_image(inst->mlx, inst->wall);
	ft_del_list(inst);
}
