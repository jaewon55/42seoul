/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:43:04 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/12 20:46:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	get_pivot_left(t_stack *stack, t_list *right)
{
	size_t	i;

	i = 0;
	while (stack->sorted_arr[i] != right->next->content)
		i++;
	return (stack->sorted_arr[(i - 1) / 2]);
}

static int	get_pivot_right(t_stack *stack, t_list *left)
{
	size_t	i;

	i = stack->a_len - 1;
	while (stack->sorted_arr[i] != left->pre->content)
		i--;
	return (stack->sorted_arr[(i + stack->a_len) / 2]);
}

int	ft_get_pivot(t_stack *stack, t_list *left, t_list *right)
{
	if (stack->top_a == left)
		return (get_pivot_left(stack, right));
	return (get_pivot_right(stack, left));
}
