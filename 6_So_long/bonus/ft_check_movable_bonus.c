/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_movable_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:21:02 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:43:11 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

static int	*get_next_loc(int keycode, int x, int y)
{
	int	*next_loc;

	next_loc = malloc(sizeof(int) * 2);
	if (!next_loc)
		ft_error(NULL);
	if (keycode == K_W || keycode == K_S)
	{
		if (keycode == K_W)
			next_loc[Y] = y - 1;
		else
			next_loc[Y] = y + 1;
		next_loc[X] = x;
	}
	else
	{
		if (keycode == K_A)
			next_loc[X] = x - 1;
		else
			next_loc[X] = x + 1;
		next_loc[Y] = y;
	}
	return (next_loc);
}

void	ft_check_movable_b(int keycode, t_mlx_inst *inst)
{
	int	*next_loc;
	int	x;
	int	y;

	x = ((short)inst->p_loc) / 64;
	y = (inst->p_loc >> 16) / 64;
	next_loc = get_next_loc(keycode, x, y);
	if (inst->map[next_loc[Y]][next_loc[X]] == '1')
	{
		free(next_loc);
		return ;
	}
	else if (inst->map[next_loc[Y]][next_loc[X]] == 'E' && inst->meso_cnt)
	{
		free(next_loc);
		return ;
	}
	else if (inst->map[next_loc[Y]][next_loc[X]] == 'C')
		ft_collect_b(inst, next_loc[X], next_loc[Y]);
	inst->key = keycode;
	inst->move_cnt++;
	free(next_loc);
}
