 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:30:59 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/10 15:33:52 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	main(int ac, char *av[])
{
	t_list	*head;
	t_stack *stack;

	head = ft_parsing_av(ac, av);
	if (!head)
	{
		ft_putstr("Error");
		return (0);
	}
	stack = ft_make_stack(head);
	if (!stack)
	{
		ft_putstr("Error");
		return (0);
	}
	ft_push_swap(stack);
	// int i = 0;
	// while (i < 100)
	// 	printf("%d ", stack->sorted_arr[i++]);
	// printf("\n\n\n");
	// printf("%d ", stack->top_a->content);
	// t_list *tmp = stack->top_a->next;
	// while (tmp != stack->top_a)
	// {
	// 	printf("%d ", tmp->content);
	// 	tmp = tmp->next;
	// }
	// printf("\n\n\n");
	ft_stack_del(stack);
	return (0);
}

// 100 : 700
// 500 : 5500



