/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:07:24 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/09 01:07:24 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_rb(t_stack *stack)
{
	t_list	*last;
	
	if (stack->b_len < 2)
		return ;
	last = stack->top_b;
	while (last->next)
		last = last->next;
	last->next = stack->top_b;
	stack->top_b->next->pre = NULL;
	stack->top_b = stack->top_b->next;
	last->next->pre = last;
	last->next->next = NULL;
}
