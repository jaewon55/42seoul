/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 19:30:54 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdlib.h>
int	main(int ac, char *av[])
{
	t_list	*head;
	t_stack	*stack;
	char	*result;

	if (ac == 1)
		return (0);
	head = ft_parsing(ac, av);
	if (!head)
		ft_error(NULL);
	stack = ft_stack_create(head);
	if (!stack)
		ft_error(NULL);
	stack->sorted_arr = NULL;
	result = ft_check_rule(stack);
	write(1, result, 3);
	ft_stack_del(stack);
	return (0);
}
