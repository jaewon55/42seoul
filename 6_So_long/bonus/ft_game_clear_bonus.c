/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_clear_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:03:02 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 14:13:34 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_game_clear(t_mlx_inst *inst)
{
	printf("-----Game Clear-----\n");
	printf("move count : %d\n", inst->move_cnt);
	ft_del_map(inst->map);
	ft_del_inst_b(inst);
	mlx_destroy_window(inst->mlx, inst->win);
	exit(0);
}
