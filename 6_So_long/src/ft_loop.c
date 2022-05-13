/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:18:23 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/14 00:17:35 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	ft_loop(t_mlx_inst *inst)
{
	t_ele	*temp;

	temp = inst->list;
	while (temp)
	{
		if (temp->c == 'C')
			ft_put_meso(inst, temp);
		else
			ft_put_escape(inst, temp);
		temp = temp->next;
	}
	ft_put_mush(inst);
	return (1);
}
