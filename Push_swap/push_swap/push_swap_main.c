/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:18:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 18:21:48 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	main(int ac, char *av[])
{
	t_list	*head;
	t_stack *stack;

	if (ac == 1)
		return (0);
	head = ft_parsing_av(ac, av);
	if (!head)
		return (write(2, "Error\n", 6));
	stack = ft_make_stack(head);
	if (!stack)
		return (write(2, "Error\n", 6));
	ft_push_swap(stack);
	ft_stack_del(stack);
	return (0);
}
