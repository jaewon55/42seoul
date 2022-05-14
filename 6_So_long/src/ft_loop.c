/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:18:23 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 21:16:10 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

int	ft_loop(t_mlx_inst *inst)
{
	t_ele	*temp;
	char	*cnt;

	mlx_do_sync(inst->mlx);
	mlx_put_image_to_window\
	(inst->mlx, inst->win, inst->wall, 0, inst->cnt_loc - 64);
	cnt = ft_itoa(inst->move_cnt);
	if (!cnt)
		ft_error();
	temp = inst->list;
	mlx_string_put\
	(inst->mlx, inst->win, 0, inst->cnt_loc, 0xFF0000, cnt);
	free(cnt);
	while (temp)
	{
		if (temp->c == 'C')
			ft_put_meso(inst, temp);
		else
			ft_put_escape(inst, temp);
		temp = temp->next;
	}
	if (inst->key == CLEAR)
		ft_game_clear(inst);
	ft_put_mush(inst);
	return (1);
}
