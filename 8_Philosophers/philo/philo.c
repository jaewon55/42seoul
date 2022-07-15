/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:25:53 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/16 02:11:09 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

static int	ft_parsing_times(t_times *times, char **av)
{
	int	start;

	times->philo_count = ft_atoi(av[1]);
	times->die_time = ft_atoi(av[2]);
	times->eat_time = ft_atoi(av[3]);
	times->sleep_time = ft_atoi(av[4]);
	start = FALSE;
	times->run = &start;
	pthread_mutex_init(&times->m_run, NULL);
	if (times->philo_count <= 0 || times->die_time < 0 \
	|| times->eat_time < 0 || times->sleep_time < 0)
		return (FALSE);
	if (av[5])
	{
		times->eat_count = ft_atoi(av[5]);
		if (times->eat_count < 0)
			return (FALSE);
	}
	else
		times->eat_count = -1;
	return (TRUE);
}

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
