/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_rule_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:50:46 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 03:03:51 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static int	ra_rule(t_stack *stack)
{
	if (!stack->top_a)
		return (1);
	stack->top_a = stack->top_a->next;
	return (1);
}

static int	rb_rule(t_stack *stack)
{
	if (!stack->top_b)
		return (1);
	stack->top_b = stack->top_b->next;
	return (1);
}

static int	rr_rule(t_stack *stack)
{
	ra_rule(stack);
	rb_rule(stack);
	return (1);
}

int	ft_rot_rule(t_stack *stack, char *rule)
{
	if (rule[1] == 'r')
		return (rr_rule(stack));
	else if (rule[1] == 'a')
		return (ra_rule(stack));
	else if (rule[1] == 'b')
		return (rb_rule(stack));
	else
		return (0);
}
