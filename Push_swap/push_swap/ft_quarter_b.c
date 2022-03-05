/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quarter_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:46:55 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/06 07:01:23 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	list_push_b(t_stack *stack, t_list *list)
{
	list->pre->next = list->next;
	list->next->pre = list->pre;
	if (stack->top_b)
	{
		list->next = stack->top_b;
		list->pre = stack->top_b->pre;
		stack->top_b->pre->next = list;
		stack->top_b->pre = list;
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

static void	push_b(t_stack *stack, t_list *list, size_t cnt_ra, int spivot)
{
	size_t	i;

	i = 0;
	if (stack->b_len > 2 && cnt_ra && stack->top_b->content <= spivot)
	{
		ft_putstr("rr\n");
		stack->top_b = stack->top_b->next;
		i++;
	}
	if (stack->b_len > 2 && !cnt_ra && stack->top_b->content <= spivot)
	{
		ft_putstr("rb\n");
		stack->top_b = stack->top_b->next;
	}
	while (i++ < cnt_ra)
		ft_putstr("ra\n");
	ft_putstr("pb\n");
	list_push_b(stack, list);
}

void	ft_quarter_b(t_stack *stack, int pivot, int spivot)
{
	size_t	i;
	size_t	total_cnt;
	t_list	*tmp;

	tmp = stack->top_a;
	total_cnt = stack->b_len + (stack->a_len + stack->b_len) / 4;
	i = 0;
	while (stack->b_len < total_cnt)
	{
		if (tmp->content <= pivot)
		{
			tmp = tmp->next;
			push_b(stack, tmp->pre, i, spivot);
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
