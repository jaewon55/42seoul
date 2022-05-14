/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:03:02 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 20:46:49 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_game_clear(t_mlx_inst *inst)
{
	printf("-----Game Clear-----\n");
	printf("move count : %d\n", inst->move_cnt);
	ft_del_map(inst->map);
	mlx_destroy_window(inst->mlx, inst->win);
	exit(0);
}
