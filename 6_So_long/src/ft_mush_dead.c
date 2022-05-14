/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mush_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:20:17 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 20:56:17 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_mush_dead(t_mlx_inst *inst, int *loc)
{
	if (inst->motion == 1)
		ft_put_img(*inst, inst->die1, loc);
	else if (inst->motion == 2)
		ft_put_img(*inst, inst->die2, loc);
	else if (inst->motion == 3)
		ft_put_img(*inst, inst->die3, loc);
	else if (inst->motion == 4)
		ft_put_img(*inst, inst->die4, loc);
	else if (inst->motion == 5)
		ft_put_img(*inst, inst->die5, loc);
	else if (inst->motion == 6)
		ft_put_img(*inst, inst->die6, loc);
	mlx_do_sync(inst->mlx);
	mlx_do_sync(inst->mlx);
	mlx_do_sync(inst->mlx);
	mlx_do_sync(inst->mlx);
	if (inst->motion++ == 6)
		printf("you dead\npress \"space\" to exit\n");
}
