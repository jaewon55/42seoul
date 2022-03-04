/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:07:21 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/04 21:20:04 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
void	*ft_del_stack(t_stack *stack)
{
	ft_list_del(stack->top_a);
	stack->top_a = NULL;
	ft_list_del(stack->top_b);
	stack->top_b = NULL;
	free(stack);
	return (NULL);
}
