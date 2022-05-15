/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:37:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:43:58 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

static void	ft_set_link(t_mlx_inst *inst, t_ele *del)
{
	if (del->prev)
		del->prev->next = del->next;
	else
		inst->list = del->next;
	if (del->next)
		del->next->prev = del->prev;
	free(del);
}

void	ft_collect_b(t_mlx_inst *inst, int x, int y)
{
	int		loc;
	t_ele	*del;

	inst->map[y][x] = '0';
	loc = y * 64;
	loc <<= 16;
	loc += x * 64;
	del = inst->list;
	while (del->location != loc)
		del = del->next;
	ft_set_link(inst, del);
	inst->meso_cnt--;
}
