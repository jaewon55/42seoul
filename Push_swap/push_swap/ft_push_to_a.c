/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:59:33 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 16:43:09 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	head_change(t_stack *stack, char *rot)
{
	if (rot[1] == 'r')
		stack->top_b = stack->top_b->pre;
	else
		stack->top_b = stack->top_b->next;
}

static void	ft_sa_rule(t_stack *stack, int push_num)
{
	int	tmp;

	tmp = stack->top_a->content;
	if (stack->top_b && stack->top_b->next->content == push_num)
	{
		ft_putstr("ss");
		stack->top_b->next->content = stack->top_b->content;
		stack->top_b->content = push_num;
	}
	else
		ft_putstr("sa");
	stack->top_a->content = stack->top_a->next->content;
	stack->top_a->next->content = tmp;
}


static void	push_a(t_stack *stack, size_t num_idx)
{
	int		*arr;
	char	*rot;

	arr = stack->sorted_arr;
	rot = ft_get_rot(stack, arr[num_idx]);
	while (stack->top_b->content != arr[num_idx])
	{
		if (num_idx > 2 && stack->top_b->content == arr[num_idx - 2])
		{
			ft_two_pre_num(stack, num_idx);
			return ;
		}
		if (num_idx > 1 && stack->top_b->content == arr[num_idx - 1])
		{
			ft_pa_rule(stack);
			if (rot[1] == 'b')
				continue ;
		}
		ft_putstr(rot);
		head_change(stack, rot);
	}
	ft_pa_rule(stack);
}

void	ft_push_to_a(t_stack *stack)
{
	int		push_num;

	push_num = stack->sorted_arr[stack->b_len - 1];
	while (stack->b_len > 0)
	{
		push_a(stack, stack->b_len - 1);
		push_num = stack->sorted_arr[stack->b_len - 1];
		if (stack->top_a->content > stack->top_a->next->content)
			ft_sa_rule(stack, push_num);
	}
}
