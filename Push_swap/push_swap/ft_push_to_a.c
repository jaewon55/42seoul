/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:59:33 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/24 20:02:53 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static size_t	ft_rb_cnt(t_list *top_b, int push_num)
{
	size_t	result;

	result = 0;
	while (top_b->content != push_num)
	{
		top_b = top_b->next;
		result++;
	}
	return (result);
}

static size_t	ft_rrb_cnt(t_list *top_b, int push_num)
{
	size_t	result;

	result = 0;
	while (top_b->content != push_num)
	{
		top_b = top_b->pre;
		result++;
	}
	return (result);
}

static void	push_a(t_stack *stack, char *str, size_t cnt)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	while (i++ < cnt)
	{
		ft_putstr(str);
		if (str[1] == 'r')
			stack->top_b = stack->top_b->pre;
		else
			stack->top_b = stack->top_b->next;
	}
	ft_putstr("pa");
	stack->top_b->pre->next = stack->top_b->next;
	stack->top_b->next->pre = stack->top_b->pre;
	tmp = stack->top_b;
	stack->top_b = stack->top_b->next;
	free(tmp);
	stack->b_len--;
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
			push_a(stack, "rb", rb_cnt);
		else
			push_a(stack, "rrb", rrb_cnt);
	}
}
