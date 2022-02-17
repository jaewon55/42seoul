/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_half_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:30:42 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/17 18:31:16 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	list_push_b(t_stack *stack, t_list *list)
{
	list->pre->next = list->next;
	list->next->pre = list->pre;
	if (stack->top_b)
	{
		stack->top_b->pre->next = list;
		stack->top_b->pre = list;
		list->next = stack->top_b;
		list->pre = stack->top_b->pre;
	}
	else
	{
		list->next = list;
		list->pre = list;
	}
	stack->top_b = list;
	stack->a_len--;
	stack->b_len++;
}

static void	push_b(t_stack *stack, t_list *list, size_t	cnt_ra)
{
	size_t	i;

	i = 0;
	if (stack->top_b && cnt_ra &&\
	list->content <= stack->sorted_arr[(stack->a_len - 1) / 4])
	{
		ft_putstr("rr");
		stack->top_b = stack->top_b->next;
		i++;
	}
	while (i++ < cnt_ra)
		ft_putstr("ra");
	ft_putstr("pb");
	list_push_b(stack, list);
}

void	ft_half_to_b(t_stack *stack, int pivot)
{
	size_t	i;
	size_t	total_cnt;
	t_list	*tmp;

	tmp = stack->top_a;
	total_cnt = (stack->a_len + 1) / 2;
	i = 0;
	while (stack->b_len < total_cnt)
	{
		if (tmp->content <= pivot)
		{
			tmp = tmp->next;
			push_b(stack, tmp->pre, i);
			i = 0;
		}
		else
		{
			tmp = tmp->next;
			i++;
		}
	}
	stack->top_a = tmp;
}
