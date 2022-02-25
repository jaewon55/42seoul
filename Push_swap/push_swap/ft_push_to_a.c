/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:59:33 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/25 21:38:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	push_a(t_stack *stack, size_t num_idx)
{
	int		*arr;
	char	*rot;

	arr = stack->sorted_arr;
	rot = ft_get_rot(stack, arr[num_idx]);
	while (stack->top_b->content != arr[num_idx])
	{
		// if (num_idx > 2 && stack->top_b->content == arr[num_idx])
		// 	return (ft_two_pre(stack, num_idx));
		if (num_idx > 1 && stack->top_b->content == arr[num_idx - 1])
		{
			ft_pa_rule(stack);
			if (rot[1] == 'b')
				continue ;
		}
		ft_putstr(rot);
		if (rot[1] == 'r')
			stack->top_b = stack->top_b->pre;
		else
			stack->top_b = stack->top_b->next;
	}
	ft_pa_rule(stack);
}

void	ft_push_to_a(t_stack *stack)
{
	int		push_num;

	push_num = stack->sorted_arr[stack->b_len - 1];
	while (stack->b_len > 0)
	{
		// test(stack, 'b');
		// test(stack, 'a');
		push_a(stack, stack->b_len - 1);
		// test(stack, 'b');
		// test(stack, 'a');
		push_num = stack->sorted_arr[stack->b_len - 1];
		if (stack->top_a->content > stack->top_a->next->content)
			ft_sa_rule(stack, push_num);
	}
}