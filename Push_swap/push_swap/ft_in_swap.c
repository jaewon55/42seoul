/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:17:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/17 21:09:00 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	rotate_and_swap(size_t rotate_cnt, size_t pb_cnt, char *rotate)
{
	size_t	i;
	size_t	j;
	char	*r_rotate;

	r_rotate = "ra";
	if (r_rotate[1] == rotate[1])
		r_rotate = "rra";
	i = 0;
	j = 0;
	while (i++ < rotate_cnt)
		ft_putstr(rotate);
	while (j++ < pb_cnt)
		ft_putstr("pb");
	if (pb_cnt)
		ft_putstr("rra");
	ft_putstr("sa");
	if (pb_cnt)
		ft_putstr("ra");
	while (--j > 0)
		ft_putstr("pa");
	while (--i > 0)
		ft_putstr(r_rotate);
}

void	ft_in_swap(t_stack *stack, t_list *left, size_t in)
{
	if (in)
	{
		if (left->idx + 1 <= stack->a_len - left->idx)
			rotate_and_swap(left->idx + 1, in, "ra");
		else
			rotate_and_swap(stack->a_len - left->idx - 1, in, "rra");
	}
	else
	{
		if (left->idx <= stack->a_len - left->idx)
			rotate_and_swap(left->idx, 0, "ra");
		else
			rotate_and_swap(stack->a_len - left->idx, 0, "rra");
	}
}
