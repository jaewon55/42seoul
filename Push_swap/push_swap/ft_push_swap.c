/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:10:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/24 21:48:27 by jaewchoi         ###   ########.fr       */
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

void	ft_push_swap(t_stack *stack)
{
	size_t	pivot_idx;
	size_t	spivot_idx;
	size_t	quarter_idx;
	int	*sorted_arr;

	quarter_idx = (stack->a_len - 1) / 8;
	spivot_idx = (stack->a_len - 1) / 4;
	pivot_idx = (stack->a_len - 1) / 2;
	sorted_arr = stack->sorted_arr;
	// 500개 100개 이상일 때 1/4로 나눠서 push b
	while (stack->a_len > 100)
	{
		ft_quarter_b(stack, sorted_arr[spivot_idx], sorted_arr[quarter_idx]);
		quarter_idx = ++pivot_idx + (stack->a_len - 1) / 8;
		spivot_idx = pivot_idx + (stack->a_len - 1) / 4;
		pivot_idx = pivot_idx + (stack->a_len - 1) / 2;
	}
	// printf("spivot : %d\tpivot : %d\n\n", sorted_arr[spivot_idx], sorted_arr[pivot_idx]);
	while (stack->a_len > 3)
	{
		ft_push_to_b(stack, sorted_arr[pivot_idx], sorted_arr[spivot_idx]);
		spivot_idx = ++pivot_idx + (stack->a_len - 1) / 4;
		pivot_idx = pivot_idx + (stack->a_len - 1) / 2;
		// printf("spivot : %d\tpivot : %d\n\n", sorted_arr[spivot_idx], sorted_arr[pivot_idx]);
		// printf("a_len : %zd\n\n", stack->a_len);
	}
	// test(stack, 'r');
	// test(stack, 'a');
	// test(stack, 'b');
	list_idx_initialize(stack->top_a);
	ft_sort_a(stack);
	ft_push_to_a(stack);
	// test(stack, 'r');
	// test(stack, 'a');
	// test(stack, 'b');
}
