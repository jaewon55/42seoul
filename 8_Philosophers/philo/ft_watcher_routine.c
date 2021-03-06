/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watcher_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:23:28 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 02:11:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>//
static int	ft_die_check(t_times time, struct timeval d_time)
{
	long	elapsed_time;

	elapsed_time = ft_get_elapsed_time(d_time);
	if (elapsed_time >= time.die_time)
		return (TRUE);
	return (FALSE);
}

void	*ft_watcher_routine(void *v_arg)
{
	t_philo	*philo;
	int		stop;

	*(((t_philo *)v_arg)->arg->times.run) = TRUE;
	usleep(200 * ((t_philo *)v_arg)->arg->times.philo_count);
	stop = FALSE;
	while (!stop)
	{
		philo = v_arg;
		while (!stop && philo)
		{
			pthread_mutex_lock(philo->mutex[D_TIME]);
			if (ft_die_check(philo->arg->times, philo->arg->d_time))
			{
				ft_philo_die(philo->arg->s_time, philo->index);
				stop = TRUE;
				*(((t_philo *)v_arg)->arg->times.run) = FALSE;
				usleep(200);
				return (NULL);
			}
			pthread_mutex_unlock(philo->mutex[D_TIME]);
			philo = philo->next;
		}
		usleep(200);
	}
	return (NULL);
}
