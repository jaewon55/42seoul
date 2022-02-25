/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:05:04 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/25 16:53:12 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	sa_rule(t_stack *stack)
{
	int	tmp;

	if (stack->top_a->content > stack->top_a->next->content)
	{
		ft_putstr("sa");
		tmp = stack->top_a->content;
		stack->top_a->content = stack->top_a->next->content;
		stack->top_a->next->content = tmp;
	}
}

void	ft_sort_a(t_stack *stack)
{
	int	big_num;

	if (!stack->a_len)
		return ;
	big_num = stack->sorted_arr[(stack->a_len + stack->b_len) - 1];
	if (stack->a_len == 3)
		ft_three_sort(stack, big_num);
	else
	{
		if (stack->top_a->content > stack->top_a->next->content)
			sa_rule(stack);
	}
}
