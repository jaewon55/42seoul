/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:37:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 23:59:58 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	ft_collect(t_mlx_inst *inst, int x, int y)
{
	int		loc;
	t_ele	*temp;

	inst->map[y][x] = '0';
	loc = y * 64;
	loc <<= 16;
	loc += x * 64;
	temp = inst->list;
	while (temp->location != loc)
		temp = temp->next;
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);
	inst->meso_cnt--;
}
