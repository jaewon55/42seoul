/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:19:53 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/08 21:19:53 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_sa(t_stack *stack)
{
	t_list	*new_head;

	if (stack->a_len < 2)
		return ;
	new_head = stack->top_a->next;
	stack->top_a->pre = stack->top_a->next;
	stack->top_a->next = stack->top_a->next->next;
	new_head->next = stack->top_a;
	new_head->pre = NULL;
	stack->top_a = new_head;
}
