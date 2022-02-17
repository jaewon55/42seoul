/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:26:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/12 15:42:52 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_make_stack(t_list *list)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_list_del(list);
		return (NULL);
	}
	stack->top_a = list;
	stack->a_len = ft_list_len(list);
	stack->b_len = 0;
	stack->sorted_arr = ft_sorted_arr(stack);
	if (!stack->sorted_arr)
	{
		ft_list_del(stack->top_a);
		free(stack);
		return (NULL);
	}
	return (stack);
}
