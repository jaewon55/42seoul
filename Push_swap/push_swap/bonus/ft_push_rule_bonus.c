/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rule_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:21:03 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 18:53:14 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
static int	pa_rule(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->top_b)
		return (1);
	tmp = stack->top_b;
	stack->top_b->pre->next = stack->top_b->next;
	stack->top_b->next->pre = stack->top_b->pre;
	stack->top_b = stack->top_b->next;
	tmp->next = tmp;
	tmp->pre = tmp;
	if ((stack->a_len)++)
	{
		tmp->next = stack->top_a;
		tmp->pre = stack->top_a->pre;
		stack->top_a->pre->next = tmp;
		stack->top_a->pre = tmp;
	}
	if (--(stack->b_len) == 0)
		stack->top_b = NULL;
	stack->top_a = tmp;
	return (1);
}

static int	pb_rule(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->top_a)
		return (1);
	tmp = stack->top_a;
	stack->top_a->pre->next = stack->top_a->next;
	stack->top_a->next->pre = stack->top_a->pre;
	stack->top_a = stack->top_a->next;
	tmp->next = tmp;
	tmp->pre = tmp;
	if ((stack->b_len)++)
	{
		tmp->next = stack->top_b;
		tmp->pre = stack->top_b->pre;
		stack->top_b->pre->next = tmp;
		stack->top_b->pre = tmp;
	}
	if (--(stack->a_len) == 0)
		stack->top_a = NULL;
	stack->top_b = tmp;
	return (1);
}

int	ft_push_rule(t_stack *stack, char *rule)
{
	if (rule[1] == 'a')
		return (pa_rule(stack));
	else if (rule[1] == 'b')
		return (pb_rule(stack));
	else
		return (0);
}
