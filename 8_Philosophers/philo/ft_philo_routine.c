/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:16:14 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 02:02:07 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	*ft_philo_routine(void *v_arg)
{
	t_arg	*arg;
	int		eat_cnt;

	arg = v_arg;
	eat_cnt = 0;
	pthread_mutex_lock(arg->mutex[F_ONE]);
	printf("0ms %d has taken a fork\n", arg->index);
	while (!ft_run_state(arg->times))
		usleep(5);
	gettimeofday(&arg->s_time, NULL);
	ft_set_time(arg->mutex[D_TIME], &arg->d_time);
	if (!ft_take_fork(arg, F_TWO))
		return (NULL);
	while (1)
	{
		ft_start_eating(arg->s_time, arg->index, arg->times.eat_time);
		if (!ft_run_state(arg->times))
			return (NULL);
		ft_set_eat_count(arg, &eat_cnt);
		pthread_mutex_unlock(arg->mutex[F_ONE]);
		pthread_mutex_unlock(arg->mutex[F_TWO]);
		ft_set_time(arg->mutex[D_TIME], &arg->d_time);
		ft_start_sleep(arg->s_time, arg->index, arg->times.sleep_time);
		if (!ft_run_state(arg->times))
			return (NULL);
		ft_start_think(arg->s_time, arg->index);
		if (!ft_run_state(arg->times))
			return (NULL);
		if (!ft_take_fork(arg, F_ONE))
			return (NULL);
		if (!ft_take_fork(arg, F_TWO))
			return (NULL);
	}
	return (NULL);
}
