/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:21:31 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 11:11:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_philo(t_times times, t_philo *head, t_share *share)
{
	unsigned int	i;

	share->start = TRUE;
	i = 0;
	while(1)
	{
		// 철학자 죽음
		if (share->state[i++ % times.philo_count] == DIE)
		{
			// stop all philo
			share->start = FALSE;
			return ;
		}
	}
}
