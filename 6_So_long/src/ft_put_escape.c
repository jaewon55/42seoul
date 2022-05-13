/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:40:19 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 19:09:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_escape(t_mlx_inst *inst, t_ele *ele)
{
	int	location[2];

	location[X] = (short)ele->location;
	location[Y] = ele->location >> 16;
	if (!inst->meso_cnt)
		ft_put_img(*inst, inst->escape2, location);
	else
		ft_put_img(*inst, inst->escape1, location);
}
