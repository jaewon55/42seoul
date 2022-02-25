/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:17:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/25 21:31:44 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
size_t	ft_rb_cnt(t_list *top_b, int push_num)
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

size_t	ft_rrb_cnt(t_list *top_b, int push_num)
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

void	ft_sa_rule(t_stack *stack, int push_num)
{
	int	tmp;

	tmp = stack->top_a->content;
	if (stack->top_b->next->content == push_num)
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
