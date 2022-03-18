/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:18:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 19:22:34 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
int	main(int ac, char *av[])
{
	t_list	*head;
	t_stack	*stack;

	if (ac == 1)
		return (0);
	head = ft_parsing(ac, av);
	if (!head)
		ft_error(NULL);
	stack = ft_stack_create(head);
	if (!stack)
		ft_error(NULL);
	stack->sorted_arr = ft_sorted_arr(stack);
	if (!stack->sorted_arr)
		ft_error(stack);
	ft_push_swap(stack);
	ft_stack_del(stack);
	return (0);
}
