/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:16:14 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 12:01:00 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_routine(void *arg)
{
	t_share			*share;
	unsigned long	time;

	share = arg;
	time = 0;
	while (share->start)
	{
		ft_pick_up(share, time);
		// has taken fork
		ft_philo_eat(share, time);
		// is eating
		ft_put_down(share, time);
		// is sleeping
		ft_philo_sleep(share, time);
		// is thinking
		ft_philo_think(share, time);
	}
}
