/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:28:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/22 19:01:36 by jaewchoi         ###   ########.fr       */
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
	int	pivot;
	t_list	*tmp;

	tmp = stack->top_a->next;
	printf("a_head : %zd\t", stack->top_a->idx);
	int	i = 1;
	while (tmp != stack->top_a)
	{
		printf("b_idx%d : %zd\t", i++, tmp->idx);
		tmp = tmp->next;
	}

	printf("\n\n");
	tmp = stack->top_b->next;
	printf("b_head : %zd\t", stack->top_b->idx);
	i = 1;
	while (tmp != stack->top_b)
	{
		printf("b_idx%d : %zd\t", i++, tmp->idx);
		tmp = tmp->next;
	}

	pivot = stack->sorted_arr[stack->b_len + (stack->a_len - 1) / 2];
	quick_sort(stack, stack->top_a, stack->top_a->pre, pivot);
}
