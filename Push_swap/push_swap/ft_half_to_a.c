/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_half_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:01:43 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/22 17:22:57 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	put_b_to_a(t_stack *stack, t_list *list, size_t rot_cnt)
{
	size_t	i;
	char	*rotate;

	rotate = "rrb";
	if (rot_cnt <= stack->b_len / 2)
		rotate = "rb";
	else
		rot_cnt = stack->b_len - rot_cnt;
	i = 0;
	while (i++ < rot_cnt)
		ft_putstr(rotate);
	ft_putstr("pa");
	stack->top_b = list->next;
	list->pre->next = list->next;
	list->next->pre = list->pre;
	free(list);
	if (!(--stack->b_len))
		stack->top_b = NULL;
}

void	ft_half_to_a(t_stack *stack, size_t pivot_idx)
{
	t_list	*tmp;
	int		pivot;
	size_t	i;

	while (stack->b_len != 0)
	{
		pivot = stack->sorted_arr[pivot_idx--];
		tmp = stack->top_b;
		i = 0;
		while (tmp->content != pivot)
		{
			tmp = tmp->next;
			i++;
		}
		put_b_to_a(stack, tmp, i);
	}
}
