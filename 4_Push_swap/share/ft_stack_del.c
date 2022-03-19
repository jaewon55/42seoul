/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:07:21 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/19 13:00:00 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>
void	*ft_stack_del(t_stack *stack)
{
	if (!stack)
		return (NULL);
	ft_list_del(stack->top_a);
	ft_list_del(stack->top_b);
	if (stack->sorted_arr)
		free(stack->sorted_arr);
	free(stack);
	return (NULL);
}
