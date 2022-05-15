/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:18:23 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:56:49 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static void	ft_put_cnt(t_mlx_inst *inst)
{
	char	*cnt;
	int		loc[2];

	mlx_do_sync(inst->mlx);
	loc[X] = 0;
	loc[Y] = inst->cnt_loc - 26;
	ft_put_img(*inst, inst->wall, loc);
	cnt = ft_itoa(inst->move_cnt);
	if (!cnt)
		ft_error(NULL);
	mlx_string_put(inst->mlx, inst->win, 25, inst->cnt_loc, 0xFF0000, cnt);
	free(cnt);
}

int	ft_loop(t_mlx_inst *inst)
{
	t_ele	*temp;

	ft_put_cnt(inst);
	temp = inst->list;
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
