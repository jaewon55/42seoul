/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:58:56 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/12 21:46:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_partition(t_stack *stack, t_list *left, t_list *right)
{
	int		pivot;
	size_t	left_i;
	size_t	right_i;
	size_t	len;
	t_list	*tmp;

	pivot = ft_get_pivot(stack, left, right);
	left_i = 0;
	right_i = 0;
	tmp = left;
	while (tmp != right)
	{
		tmp = tmp->next;
		right_i++;
		len
	}
	while (left_i < right_i)
	{
		tmp = left;
		while (left_i <= )
	}
}
