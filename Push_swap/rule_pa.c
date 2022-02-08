/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:50:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/08 23:50:36 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_pa(t_stack *stack)
{
	if (!stack->top_b)
		return ;
	stack->top_a->pre = stack->top_b;
	stack->top_b->next->pre = NULL;
	stack->top_b = stack->top_b->next;
	stack->top_a->pre->next = stack->top_a;
	stack->top_a = stack->top_a->pre;
	stack->a_len++;
	stack->b_len--;
}
