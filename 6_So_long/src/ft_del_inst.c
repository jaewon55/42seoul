/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:44:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:38:40 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_del_inst(t_mlx_inst *inst)
{
	mlx_destroy_image(inst->mlx, inst->meso);
	mlx_destroy_image(inst->mlx, inst->mush);
	mlx_destroy_image(inst->mlx, inst->escape);
	mlx_destroy_image(inst->mlx, inst->space);
	mlx_destroy_image(inst->mlx, inst->wall);
}
