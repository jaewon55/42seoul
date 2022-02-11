/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:37:32 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/11 20:51:05 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	ft_copy_node(int *arr, t_list *list)
{
	t_list	*tmp;
	size_t	i;

	tmp = list->next;
	i = 1;
	while (tmp != list)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	arr[0] = list->content;
}

int	*ft_sorted_arr(t_stack *stack)
{
	int	*arr;

	arr = malloc(sizeof(int) * stack->a_len);
	if (!arr)
		return (NULL);
	ft_copy_node(arr, stack->top_a);
	arr = ft_merge_sort(arr, stack->a_len - 1);
	if (!arr)
		return (NULL);
	return (arr);
}
