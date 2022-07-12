/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:25:53 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 10:33:25 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
int	ft_parsing_arg(t_times *times, char **av)
{
	times->philo_count = ft_atoi(av[1]);
	times->die_time = ft_atoi(av[2]);
	times->eat_time = ft_atoi(av[3]);
	times->sleep_time = ft_atoi(av[4]);
	if (times->philo_count <= 0 || times->die_time < 0\ 
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
	t_share	*share;
	t_philo	*head;

	if (ac == 5 && ac == 6)
	{
		if (!ft_parsing_arg(&times, av))
			return (ft_argument_valid_error());
		share = ft_init_share(times);
		if (!share)
			return (ft_share_error());
		head = ft_create_thread(times.philo_count, share);
		if (!head)
			return (ft_create_thread_error(share));
		ft_start_philo(times, head);
	}
	else
		return (ft_argument_size_error());
	return (0);
}
