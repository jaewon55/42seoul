/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:20:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/11 21:41:29 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void merge(t_arr *arr, size_t left, size_t mid, size_t right)
{
	size_t	l_idx;
	size_t	r_idx;
	size_t	tmp_idx;

	l_idx = left;
	r_idx = mid + 1;
	tmp_idx = left;
	while (l_idx <= mid && r_idx <= right)
		if (arr->arr[l_idx] <= arr->arr[r_idx])
			arr->tmp_arr[tmp_idx++] = arr->arr[l_idx++];
		else
			arr->tmp_arr[tmp_idx++] = arr->arr[r_idx++];
	while (l_idx <= mid)
		arr->tmp_arr[tmp_idx++] = arr->arr[l_idx++];
	while (left < tmp_idx)
	{
		arr->arr[left] = arr->tmp_arr[left];
		left++;
	}
}

static void	merge_sort(t_arr *arr, size_t left, size_t right)
{
	size_t	mid;

	if (left >= right)
		return ;
	mid = (left / 2) + (right / 2);
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int	*ft_merge_sort(int *arr, size_t len)
{
	t_arr	*arr_struct;

	arr_struct = malloc(sizeof(t_arr));
	if (!arr_struct)
	{
		free(arr);
		return (NULL);
	}
	arr_struct->tmp_arr = malloc(sizeof(int) * len);
	if (!arr_struct->tmp_arr)
	{
		free(arr);
		free(arr_struct);
		return (NULL);
	}
	arr_struct->arr = arr;
	merge_sort(arr_struct, 0, len - 1);
	free(arr_struct->tmp_arr);
	free(arr_struct);
	return (arr);
}
