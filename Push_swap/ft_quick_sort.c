/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:28:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/12 21:40:46 by jaewchoi         ###   ########.fr       */
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

static void	quick_sort(t_stack *stack, t_list *left, t_list *right)
{
	int pivot;

	if (left >= right)
		return ;
	pivot = ft_partition(stack, left, right);
	quick_sort(stack, left, get_pivot_list(stack, pivot)->pre);
	quick_sort(stack, get_pivot_list(stack, pivot)->next, right);
}

void	ft_quick_sort(t_stack *stack)
{
	quick_sort(stack, stack->top_a, stack->top_a->pre);
}
