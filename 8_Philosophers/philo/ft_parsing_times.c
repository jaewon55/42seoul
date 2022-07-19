/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_times.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:08:09 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 01:14:26 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	ft_times_init(t_times *times, char **av)
{
	times->run = malloc(sizeof(int));
	if (!times->run)
		return (FALSE);
	times->m_run = malloc(sizeof(pthread_mutex_t));
	if (!times->m_run)
	{
		free(times->run);
		return (FALSE);
	}
	times->philo_count = ft_atoi(av[1]);
	times->die_time = ft_atoi(av[2]);
	times->eat_time = ft_atoi(av[3]);
	times->sleep_time = ft_atoi(av[4]);
	if (av[5])
		times->eat_count = ft_atoi(av[5]);
	else
		times->eat_count = -1;
	return (TRUE);
}

int	ft_parsing_times(t_times *times, char **av)
{
	if (!ft_times_init(times, av))
		return (FALSE);
	pthread_mutex_init(times->m_run, NULL);
	if (times->philo_count <= 0 || times->die_time < 0 || times->eat_time < 0 \
	|| times->sleep_time < 0 || (av[5] && times->eat_count < 0))
	{
		pthread_mutex_destroy(times->m_run);
		free(times->run);
		return (FALSE);
	}
	return (TRUE);
}
