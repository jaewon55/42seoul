/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:47:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:16:08 by jaewchoi         ###   ########.fr       */
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
	inst->meso = mlx_xpm_file_to_image(inst->mlx, MESO, &a, &b);
	inst->mush = mlx_xpm_file_to_image(inst->mlx, MUSH, &a, &b);
	inst->escape = mlx_xpm_file_to_image(inst->mlx, ESCAPE, &a, &b);
}
