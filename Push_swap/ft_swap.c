/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:23:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/16 20:22:59 by jaewchoi         ###   ########.fr       */
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
	ft_putstr("rra");
	ft_putstr("sa");
	ft_putstr("ra");
	while (--j > 0)
		ft_putstr("pa");
	while (--i > 0)
		ft_putstr(r_rotate);
}

static void	swap_rule(t_stack *stack, t_list *left, t_list *right)
{
	size_t	between_cnt;

	between_cnt = right->idx - left->idx - 1;
	// left와 right가 붙어 있는가?
	if (between_cnt) // 떨어져 있다면
	{
		// left를 last로 이동하는데 ra와 rra 중 뭐가 더 빠른가?
		if (left->idx + 1 <= stack->a_len - left->idx) // ra가 빠르거나 같음
			rotate_and_swap(left->idx + 1, between_cnt, "ra");
		else
			rotate_and_swap(stack->a_len - left->idx - 1, between_cnt, "rra");
	}
	else // 붙어있다면
	{
		// left를 top으로 이동하는데 뭐가 더 빠른가?
		if (left->idx <= stack->a_len - left->idx) // ra가 더 빠르거나 같음
			rotate_and_swap(left->idx, 0, "ra");
		else // rra가 더 빠름
			rotate_and_swap(stack->a_len - left->idx, 0, "rra");
	}
}

void	ft_swap(t_stack *stack, t_list *left, t_list *right, int tmp)
{
	if (left == right)
		return ;
	left->content = right->content;
	right->content = tmp;
	swap_rule(stack, left, right);
}
