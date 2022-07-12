/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_share.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:35:38 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 11:05:35 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

t_share	*ft_init_share(t_times times)
{
	t_share	*share;

	share = malloc(sizeof(int) * times->philo_count);
	if (!share)
		return (NULL);
	share->state = malloc(sizeof(int) * times->philo_count);
	share->fork = malloc(sizeof(int) * times->philo_count);
	if (!share->state || !share->fork)
	{
		free(share->state);
		free(share->fork);
		free(share);
		return (NULL);
	}
	memset(share->state, 0, sizeof(int) * times->philo_count);
	pthread_mutex_init(&share->m_state, NULL);
	pthread_mutex_init(&share->fork, NULL);
	share->start = FALSE;
	return (share);
}                
