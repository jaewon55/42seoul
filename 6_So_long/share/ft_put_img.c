/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:44:12 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:28:30 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_put_img(t_mlx_inst inst, void *img, int *location)
{
	if (!img)
		return ;
	mlx_put_image_to_window(inst.mlx, inst.win, img, location[X], location[Y]);
}
