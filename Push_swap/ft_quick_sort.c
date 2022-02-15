/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:28:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/15 15:42:04 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static t_list	*get_pivot_list(t_stack *stack, int pivot)
{
	t_list	*tmp;

	tmp = stack->top_a;
	while (tmp->content != pivot)
		tmp = tmp->next;
	return (tmp);
}

static t_list	*next_pivot(t_stack *stack, t_list *left, t_list *right)
{
	int		next_pivot;
	t_list	*result;

	next_pivot = stack->sorted_arr[left->idx + (right->idx - left->idx) / 2];
	result = left;
	while (result->content != next_pivot)
		result = result->next;
	return (result);
}

static void	quick_sort(t_stack *stack, t_list *left, t_list *right, int pivot)
{
	t_list	*tmp;

	if (left->idx >= right->idx)
		return ;
	ft_part(stack, left, right, pivot);
	tmp = get_pivot_list(stack, pivot);
	quick_sort(stack, left, tmp->pre, next_pivot(stack, left, tmp->pre));
	quick_sort(stack, tmp->next, right, next_pivot(stack, tmp->next, right));
}

void	ft_quick_sort(t_stack *stack)
{
	int	first_pivot;

	first_pivot = stack->sorted_arr[(stack->a_len - 1) / 2];
	quick_sort(stack, stack->top_a, stack->top_a->pre, first_pivot);
}
