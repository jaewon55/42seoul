/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:25:53 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/18 20:08:33 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_times	times;
	t_philo	*head;

	if (ac == 5 || ac == 6)
	{
		if (!ft_parsing_times(&times, av))
			return (ft_argument_valid_error(times));
		head = ft_create_philo_list(times.philo_count);
		if (!head)
			return (ft_create_list_error(times));
		if (!ft_create_arg(times, head))
			return (ft_create_arg_error(times));
		ft_create_philo(head);
		ft_create_watcher(head);
	}
	else
		return (ft_argument_size_error());
	return (0);
}
