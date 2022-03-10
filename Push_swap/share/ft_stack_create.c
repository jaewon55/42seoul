/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:44:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 19:18:41 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>
t_stack	*ft_stack_create(t_list *head)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ((t_stack *)ft_list_del(head));
	stack->top_a = head;
	stack->top_b = NULL;
	stack->a_len = ft_list_len(head);
	stack->b_len = 0;
	return (stack);
}
