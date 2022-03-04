/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:37:43 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/09 01:37:43 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_rrb(t_stack *stack)
{
	t_list	*last;

	if (stack->b_len < 2)
		return ;
	last = stack->top_b;
	while (last->next)
		last = last->next;
	last->pre->next = NULL;
	last->pre = NULL;
	stack->top_b->pre = last;
	last->next = stack->top_b;
	stack->top_b = last;
}
