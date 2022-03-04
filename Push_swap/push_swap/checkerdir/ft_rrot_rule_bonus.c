/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrot_rule_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:59:32 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 03:05:28 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static int	rra_rule(t_stack *stack)
{
	if (!stack->top_a)
		return (1);
	stack->top_a = stack->top_a->pre;
	return (1);
}

static int	rrb_rule(t_stack *stack)
{
	if (!stack->top_b)
		return (1);
	stack->top_b = stack->top_b->pre;
	return (1);
}

static int	rrr_rule(t_stack *stack)
{
	rra_rule(stack);
	rrb_rule(stack);
	return (1);
}

int	ft_rrot_rule(t_stack *stack, char *rule)
{
	if (rule[2] == 'r')
		return (rrr_rule(stack));
	else if (rule[2] == 'a')
		return (rra_rule(stack));
	else if (rule[3] == 'b')
		return (rrb_rule(stack));
	else
		return (0);
}
