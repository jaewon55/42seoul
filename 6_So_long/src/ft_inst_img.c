/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:47:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 18:13:12 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_inst_img(t_mlx_inst	*inst)
{
	int	a;
	int	b;

	inst->space = mlx_xpm_file_to_image(inst->mlx, SPACE, &a, &b);
	inst->wall = mlx_xpm_file_to_image(inst->mlx, WALL, &a, &b);
	inst->meso1 = mlx_xpm_file_to_image(inst->mlx, MESO1, &a, &b);
	inst->meso2 = mlx_xpm_file_to_image(inst->mlx, MESO2, &a, &b);
	inst->meso3 = mlx_xpm_file_to_image(inst->mlx, MESO3, &a, &b);
	inst->meso4 = mlx_xpm_file_to_image(inst->mlx, MESO4, &a, &b);
	inst->mush1 = mlx_xpm_file_to_image(inst->mlx, MUSH1, &a, &b);
	inst->mush2 = mlx_xpm_file_to_image(inst->mlx, MUSH2, &a, &b);
	inst->mush3 = mlx_xpm_file_to_image(inst->mlx, MUSH3, &a, &b);
	inst->mush4 = mlx_xpm_file_to_image(inst->mlx, MUSH4, &a, &b);
	inst->escape1 = mlx_xpm_file_to_image(inst->mlx, ESCAPE_C, &a, &b);
	inst->escape2 = mlx_xpm_file_to_image(inst->mlx, ESCAPE_O, &a, &b);
}
