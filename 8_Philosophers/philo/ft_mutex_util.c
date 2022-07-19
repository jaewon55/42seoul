/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:09:24 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 00:59:13 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_run_state(t_times time)
{
	int	result;

	pthread_mutex_lock(time.m_run);
	result = *(time.run);
	pthread_mutex_unlock(time.m_run);
	return (result);
}

void	ft_set_time(pthread_mutex_t *mut, struct timeval *time)
{
	pthread_mutex_lock(mut);
	gettimeofday(time, NULL);
	pthread_mutex_unlock(mut);
}

void	ft_set_eat_count(t_arg *arg, int *count)
{
	(*count)++;
	if (*count == arg->times.eat_count)
	{
		pthread_mutex_lock(arg->mutex[OVER_EAT]);
		arg->over_eat = TRUE;
		pthread_mutex_unlock(arg->mutex[OVER_EAT]);
	}
	
}
