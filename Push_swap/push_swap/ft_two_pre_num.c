/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_pre_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:39:31 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 13:27:08 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	get_push_num(t_stack *stack, size_t num_idx)
{
	size_t	cur_cnt;
	size_t	pre_cnt;

	cur_cnt = ft_get_rot_cnt(stack, stack->sorted_arr[num_idx]);
	pre_cnt = ft_get_rot_cnt(stack, stack->sorted_arr[num_idx - 1]);
	if (cur_cnt <= pre_cnt)
		return (stack->sorted_arr[num_idx]);
	return (stack->sorted_arr[num_idx - 1]);
}

static void	two_pre_num_to_last(t_stack *stack, char *rot, int num)
{
	if (stack->top_b->content != num && rot[1] != 'r')
	{
		ft_putstr("rr");
		stack->top_b = stack->top_b->next;
		stack->top_a = stack->top_a->next;
	}
	else
	{
		ft_putstr("ra");
		stack->top_a = stack->top_a->next;
	}
}

static void	num_to_a(t_stack *stack, size_t num_idx, int p_num)
{
	char	*rot;

	rot = ft_get_rot(stack, p_num);
	if (stack->top_a->pre->content != stack->sorted_arr[num_idx - 2])
		two_pre_num_to_last(stack, rot, p_num);
	while (stack->top_b->content != p_num)
	{
		ft_putstr(rot);
		if (rot[1] == 'r')
			stack->top_b = stack->top_b->pre; 
		else
			stack->top_b = stack->top_b->next;
	}
	ft_pa_rule(stack);
	if (stack->top_a->content > stack->top_a->next->content)
	{
		ft_putstr("sa");
		stack->top_a->content = stack->top_a->next->content;
		stack->top_a->next->content = p_num;
	}
}

static void	two_num_to_a(t_stack *stack, size_t num_idx)
{
	int	push_num;

	push_num = get_push_num(stack, num_idx);
	if (push_num == stack->sorted_arr[num_idx])
	{
		num_to_a(stack, num_idx, push_num);
		num_to_a(stack, num_idx, stack->sorted_arr[num_idx - 1]);
		return ;
	}
	num_to_a(stack, num_idx, push_num);
	num_to_a(stack, num_idx, stack->sorted_arr[num_idx]);
}

void	ft_two_pre_num(t_stack *stack, size_t num_idx)
{
	ft_pa_rule(stack);
	if (stack->top_a->next->content == stack->sorted_arr[num_idx - 1])
		num_to_a(stack, num_idx, stack->sorted_arr[num_idx]);
	else
		two_num_to_a(stack, num_idx);
	ft_putstr("rra");
	stack->top_a = stack->top_a->pre;
}
