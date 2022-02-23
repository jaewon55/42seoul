/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:23:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/23 16:06:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_swap(t_stack *stack, t_list *left, t_list *right, int tmp)
{
	size_t	between_in;
	size_t	between_out;

	if (left == right)
		return ;
	left->content = right->content;
	right->content = tmp;
	between_in = right->idx - left->idx - 1;
	between_out = stack->a_len - (between_in + 2);
	if (between_in < between_out)
		ft_in_swap(stack, left, between_in);
	else
		ft_out_swap(stack, right, between_out);
}
