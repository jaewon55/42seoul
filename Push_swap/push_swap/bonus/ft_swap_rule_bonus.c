/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_rule_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:03:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 18:52:58 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
static int	sa_rule(t_stack *stack)
{
	int	tmp;

	if (!stack->top_a)
		return (1);
	tmp = stack->top_a->content;
	stack->top_a->content = stack->top_a->next->content;
	stack->top_a->next->content = tmp;
	return (1);
}

static int	sb_rule(t_stack *stack)
{
	int	tmp;

	if (!stack->top_b)
		return (1);
	tmp = stack->top_b->content;
	stack->top_b->content = stack->top_b->next->content;
	stack->top_b->next->content = tmp;
	return (1);
}

static int	ss_rule(t_stack *stack)
{
	sa_rule(stack);
	sb_rule(stack);
	return (1);
}

int	ft_swap_rule(t_stack *stack, char *rule)
{
	if (rule[1] == 's')
		return (ss_rule(stack));
	else if (rule[1] == 'a')
		return (sa_rule(stack));
	else if (rule[1] == 'b')
		return (sb_rule(stack));
	else
		return (0);
}
