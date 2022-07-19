/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:04:09 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 13:24:26 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died
int	ft_take_fork(t_arg *arg, int f_num)
{
	if (pthread_mutex_lock(arg->mutex[f_num]))
		return (FALSE);
	if (!ft_run_state(arg->times))
		return (FALSE);
	printf("%ldms %d has taken a fork\n", \
	ft_get_elapsed_time(arg->s_time), arg->index);
	return (TRUE);
}

void	ft_start_eating(struct timeval s_time, int idx, int eat_time)
{
	printf("%ldms %d is eating\n", ft_get_elapsed_time(s_time), idx);
	usleep(eat_time * 1000);
}

void	ft_start_sleep(struct timeval s_time, int idx, int sleep_time)
{
	printf("%ldms %d is sleeping\n", ft_get_elapsed_time(s_time), idx);
	usleep(sleep_time * 1000);
}

void	ft_start_think(struct timeval s_time, int idx)
{
	printf("%ldms %d is thinking\n", ft_get_elapsed_time(s_time), idx);
	// usleep(100);
}

void	ft_philo_die(struct timeval s_time, int idx)
{
	printf("%ldms %d died\n", ft_get_elapsed_time(s_time), idx);
}
