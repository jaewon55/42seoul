/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:49:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/24 17:16:24 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	sa_rule(t_stack *stack)
{
	int	tmp;

	if (stack->top_a->content > stack->top_a->next->content)
	{
		ft_putstr("sa");
		tmp = stack->top_a->content;
		stack->top_a->content = stack->top_a->next->content;
		stack->top_a->next->content = tmp;
	}
}

static void	rra_rule(t_stack *stack)
{
	ft_putstr("rra");
	stack->top_a = stack->top_a->pre;
	sa_rule(stack);
}

static void	ra_rule(t_stack *stack)
{
	ft_putstr("ra");
	stack->top_a = stack->top_a->next;
	sa_rule(stack);
}

void	ft_three_sort(t_stack *stack, int big_num)
{
	t_list	*tmp;

	tmp = stack->top_a;
	if (tmp->next->content == big_num)
		tmp = tmp->next;
	else if (tmp->pre->content == big_num)
		tmp = tmp->pre;
	if (tmp->idx == 0)
		ra_rule(stack);
	else if (tmp->idx == 1)
		rra_rule(stack);
	else
		sa_rule(stack);
}
