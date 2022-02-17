/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:18:52 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/17 21:10:17 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	rotate_and_swap(size_t rotate_cnt, size_t pb_cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i++ < rotate_cnt)
		ft_putstr("rra");
	while (j++ < pb_cnt)
		ft_putstr("pb");
	ft_putstr("rra");
	ft_putstr("sa");
	ft_putstr("ra");
	while (--j > 0)
		ft_putstr("pa");
	while (--i > 0)
		ft_putstr("ra");
}

void	ft_out_swap(t_stack *stack, t_list *right, size_t out)
{
	if (out)
		rotate_and_swap((stack->a_len - 1) - right->idx, out);
	else
	{
		ft_putstr("rra");
		ft_putstr("sa");
		ft_putstr("ra");
	}
}
