/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:10:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/22 18:49:49 by jaewchoi         ###   ########.fr       */
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
	size_t	pivot_idx;

	pivot_idx = (stack->a_len - 1) / 2;
	ft_half_to_b(stack, stack->sorted_arr[pivot_idx]);
	list_idx_initialize(stack->top_a);
	list_idx_initialize(stack->top_b);
	ft_quick_sort(stack);
	ft_half_to_a(stack, pivot_idx);
}
