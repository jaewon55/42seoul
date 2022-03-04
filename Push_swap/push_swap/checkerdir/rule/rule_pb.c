/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:49:50 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/08 23:49:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_pb(t_stack *stack)
{
	if (!stack->top_a)
		return ;
	stack->top_b->pre = stack->top_a;
	stack->top_a->next->pre = NULL;
	stack->top_a = stack->top_a->next;
	stack->top_b->pre->next = stack->top_b;
	stack->top_b = stack->top_b->pre;
	stack->b_len++;
	stack->a_len--;
}
