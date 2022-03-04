/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:50:46 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/09 00:50:46 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_ra(t_stack *stack)
{
	t_list	*last;

	if (stack->a_len < 2)
		return ;
	last = stack->top_a;
	while (last->next)
		last = last->next;
	last->next = stack->top_a;
	stack->top_a->next->pre = NULL;
	stack->top_a = stack->top_a->next;
	last->next->pre = last;
	last->next->next = NULL;
}
