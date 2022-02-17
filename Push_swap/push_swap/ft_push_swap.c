/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:10:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/17 18:34:36 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	list_idx_initialize(t_list *head)
{
	t_list	*tmp;
	size_t	i;

	tmp = head->next;
	head->idx = 0;
	i = 1;
	while (tmp != head)
	{
		tmp->idx = i++;
		tmp = tmp->next;
	}
}

void	ft_push_swap(t_stack *stack)
{
	ft_half_to_b(stack, stack->sorted_arr[(stack->a_len - 1) / 2]);
	list_idx_initialize(stack->top_a);
	list_idx_initialize(stack->top_b);
	// ft_quick_sort(stack);
}
