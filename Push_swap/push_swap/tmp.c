/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:59:33 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/06 07:06:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	push_pre_num(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top_b;
	tmp->next->pre = tmp->pre;
	tmp->pre->next = tmp->next;
	stack->top_b = tmp->next;
	tmp->next = stack->top_a;
	tmp->pre = stack->top_a->pre;
	stack->top_a = tmp;
	ft_putstr("pa\n");
	stack->b_len--;
	
}

static void	push_a(t_stack *stack, char *str, size_t cnt, size_t num_idx)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = stack->sorted_arr;
	while (i++ < cnt)
	{
		if (num_idx > 2 && (stack->top_b->content == arr[num_idx - 1] ||\
		stack->top_b->content == arr[num_idx - 2]))
		{
			push_pre_num(stack);
			if (str[1] == 'b')
				continue ;
		}
		ft_putstr(str);
		if (str[1] == 'r')
			stack->top_b = stack->top_b->pre;
		else
			stack->top_b = stack->top_b->next;
	}
}

void	ft_push_to_a(t_stack *stack)
{
	int		push_num;
	size_t	rb_cnt;
	size_t	rrb_cnt;

	while (stack->b_len > 0)
	{
		push_num = stack->sorted_arr[stack->b_len - 1];
		rb_cnt = ft_rb_cnt(stack->top_b, push_num);
		rrb_cnt = ft_rrb_cnt(stack->top_b, push_num);
		if (rb_cnt < rrb_cnt)
			push_a(stack, "rb\n", rb_cnt, stack->b_len - 1);
		else
			push_a(stack, "rrb\n", rrb_cnt, stack->b_len - 1);
	}
}
