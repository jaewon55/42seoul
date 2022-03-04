/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 03:12:39 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
int	main(int ac, char *av[])
{
	t_list	*head;
	t_stack	*stack;
	char	*result;

	if (ac == 1)
		return (0);
	head = ft_parsing(ac, av);
	if (!head)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	stack = ft_create_stack(head);
	if (!stack)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	result = ft_check_rule(stack);
	write(1, result, 3);
	ft_del_stack(stack);
	return (0);
}

	// t_list	*tmp;
	// tmp = head->next;
	// printf("%d\t", head->content);
	// while (tmp != head)
	// {
	// 	printf("%d\t", tmp->content);
	// 	tmp = tmp->next;
	// }