/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:10:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 17:00:05 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	list_idx_initialize(t_list *head)
{
	t_list	*tmp;
	size_t	i;

	if (!head)
		return ;
	tmp = head->next;
	head->idx = 0;
	i = 1;
	while (tmp != head)
	{
		tmp->idx = i++;
		tmp = tmp->next;
	}
}

static void	half_to_b(t_stack *stack, size_t pivot_idx, size_t spivot_idx)
{
	int		*sorted_arr;
	size_t	quarter_cnt;

	sorted_arr = stack->sorted_arr;
	quarter_cnt = stack->a_len / 4;
	ft_quarter_b(stack, sorted_arr[pivot_idx], sorted_arr[spivot_idx]);
	pivot_idx += quarter_cnt;
	spivot_idx += quarter_cnt;
	ft_quarter_b(stack, sorted_arr[pivot_idx], sorted_arr[spivot_idx]);
}

void	ft_push_swap(t_stack *stack)
{
	size_t	pivot_idx;
	size_t	spivot_idx;
	int		*sorted_arr;

	pivot_idx = (stack->a_len - 1) / 2;
	spivot_idx = (stack->a_len - 1) / 4;
	sorted_arr = stack->sorted_arr;
	if (stack->a_len >= 500)
	{
		half_to_b(stack, (stack->a_len - 1) / 4, (stack->a_len - 1) / 8);
		spivot_idx = ++pivot_idx + (stack->a_len - 1) / 4;
		pivot_idx = pivot_idx + (stack->a_len - 1) / 2;
	}
	while (stack->a_len > 3)
	{
		ft_push_to_b(stack, sorted_arr[pivot_idx], sorted_arr[spivot_idx]);
		spivot_idx = ++pivot_idx + (stack->a_len - 1) / 4;
		pivot_idx = pivot_idx + (stack->a_len - 1) / 2;
	}
	list_idx_initialize(stack->top_a);
	ft_sort_a(stack);
	ft_push_to_a(stack);
}
