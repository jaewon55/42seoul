/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:44:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/04 20:25:16 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static size_t	ft_list_len(t_list *head)
{
	t_list	*tmp;
	size_t	i;

	tmp = head->next;
	i = 1;
	while (tmp != head)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack *ft_create_stack(t_list *head)
{
    t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_list_del(head);
		return (NULL);
	}
	stack->top_a = head;
	stack->a_len = ft_list_len(head);
	stack->b_len = 0;
	return (stack);
}
