/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:17:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 13:13:37 by jaewchoi         ###   ########.fr       */
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

char	*ft_get_rot(t_stack *stack, int num)
{
	if (ft_rb_cnt(stack->top_b, num) < ft_rrb_cnt(stack->top_b, num))
		return ("rb");
	return ("rrb");
}

size_t	ft_get_rot_cnt(t_stack *stack, int num)
{
	size_t	rb_cnt;
	size_t	rrb_cnt;

	rb_cnt = ft_rb_cnt(stack->top_b, num);
	rrb_cnt = ft_rrb_cnt(stack->top_b, num);
	if (rb_cnt < rrb_cnt)
		return (rb_cnt);
	return (rrb_cnt);
}

void	ft_pa_rule(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top_b;
	tmp->pre->next = tmp->next;
	tmp->next->pre = tmp->pre;
	stack->top_b = tmp->next;
	tmp->next = stack->top_a;
	tmp->pre = stack->top_a->pre;
	stack->top_a->pre->next = tmp;
	stack->top_a->pre = tmp;
	stack->top_a = tmp;
	ft_putstr("pa");
	stack->b_len--;
}
