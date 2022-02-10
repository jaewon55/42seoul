/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:32:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/08 21:32:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_sb(t_stack *stack)
{
	t_list	*new_head;

	if (stack->b_len < 2)
		return ;
	new_head = stack->top_b->next;
	stack->top_b->pre = stack->top_b->next;
	stack->top_b->next = stack->top_b->next->next;
	new_head->next = stack->top_b;
	new_head->pre = NULL;
	stack->top_b = new_head;
}
