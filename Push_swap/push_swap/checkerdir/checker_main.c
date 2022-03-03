/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 17:20:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
int	main(int ac, char *av[])
{
	t_list	*head;

	if (ac == 1)
		return (0);
	head = ft_parsing(ac, av);
	if (!head)
		return (write(2, "Error\n", 6));
}
