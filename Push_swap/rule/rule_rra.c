/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:22:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/09 01:22:16 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rule_rra(t_stack *stack)
{
	t_list	*last;

	if (stack->a_len < 2)
		return ;
	last = stack->top_a;
	while (last->next)
		last = last->next;
	last->pre->next = NULL;
	last->pre = NULL;
	stack->top_a->pre = last;
	last->next = stack->top_a;
	stack->top_a = last;
}
