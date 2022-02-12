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
// void	input_check(t_list *head)
// {
// 	if (!head)
// 		printf("ERROR\n");
// 	else
// 	{
// 		t_list *tmp = head->next;
// 		printf ("%d\t", head->content);
// 		while (tmp != head)
// 		{
// 			printf("%d\t", tmp->content);
// 			tmp = tmp->next;
// 		}
// 		printf("\n");
// 	}
// }

int	main(int ac, char *av[])
{
	t_list	*head;
	t_stack *stack;

	head = ft_parsing_av(ac, av);
	if (!head)
		return (0);
	stack = ft_make_stack(head);
	if (!stack)
		return (0);
	push_swap(stack);
	return (0);
}
