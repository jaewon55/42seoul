/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:58:56 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/15 15:41:47 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_part(t_stack *stack, t_list *left, t_list *right, t_list *pivot)
{
	while (left->idx < right->idx)
	{
		while (left != stack->top_a->pre && left->content <= pivot->content)
			left = left->next;
		while (right != stack->top_a && right->content >= pivot->content)
			right = right->pre;
		if (left->idx < right->idx)
			ft_swap(stack, left, right, left->content);
	}
	if (left == right)
		ft_swap(stack, right, pivot, right->content);
	else if (pivot->idx > right->idx)
		ft_swap(stack, right->next, pivot, right->next->content);
	else
		ft_swap(stack, pivot, right, pivot->content);
}
