/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:29:35 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/17 20:59:47 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_stack_del(t_stack *stack)
{
	ft_list_del(stack->top_a);
	stack->top_a = NULL;
	free(stack->sorted_arr);
	stack->sorted_arr = NULL;
	free(stack);
}
