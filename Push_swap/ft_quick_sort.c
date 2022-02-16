/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:28:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/16 19:30:37 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static t_list	*get_pivot_list(t_list *left, int pivot)
{
	t_list	*tmp;

	tmp = left;
	while (tmp->content != pivot)
		tmp = tmp->next;
	return (tmp);
}

static int	next_pivot(t_stack *stack, t_list *left, t_list *right)
{
	int		next_pivot;

	next_pivot = stack->sorted_arr[left->idx + (right->idx - left->idx) / 2];
	return (next_pivot);
}

static void	quick_sort(t_stack *stack, t_list *left, t_list *right, int pivot)
{
	t_list	*tmp;

	if (left->idx >= right->idx \
	|| (left->next == right && left->content < right->content))
		return ;
	ft_part(stack, left, right, get_pivot_list(left, pivot));
	tmp = get_pivot_list(left, pivot);
	quick_sort(stack, left, tmp->pre, next_pivot(stack, left, tmp->pre));
	quick_sort(stack, tmp->next, right, next_pivot(stack, tmp->next, right));
}

void	ft_quick_sort(t_stack *stack)
{
	int	first_pivot;
	
	first_pivot = stack->sorted_arr[(stack->a_len - 1) / 2];
	quick_sort(stack, stack->top_a, stack->top_a->pre, first_pivot);
}
