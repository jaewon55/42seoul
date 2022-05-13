/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_meso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:10:26 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 19:14:52 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_meso(t_mlx_inst *inst, t_ele *ele)
{
	int	location[2];

	location[X] = (short)ele->location;
	location[Y] = ele->location >> 16;
	if (ele->status == 1)
		ft_put_img(*inst, inst->meso1, location);
	else if (ele->status == 2)
		ft_put_img(*inst, inst->meso2, location);
	else if (ele->status == 3)
		ft_put_img(*inst, inst->meso3, location);
	else if (ele->status == 4)
		ft_put_img(*inst, inst->meso4, location);
	if (ele->status++ == 4)
		ele->status = 1;
}
