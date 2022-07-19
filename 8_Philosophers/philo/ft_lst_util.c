/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:13:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 01:17:42 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static int	ft_init_mutex(pthread_mutex_t **arr)
{
	arr[F_ONE] = malloc(sizeof(pthread_mutex_t));
	arr[OVER_EAT] = malloc(sizeof(pthread_mutex_t));
	arr[D_TIME] = malloc(sizeof(pthread_mutex_t));
	if (!arr[F_ONE] || !arr[OVER_EAT] || !arr[D_TIME])
	{
		free(arr[F_ONE]);
		free(arr[OVER_EAT]);
		free(arr[D_TIME]);
		return (FALSE);
	}
	pthread_mutex_init(arr[F_ONE], NULL);
	pthread_mutex_init(arr[OVER_EAT], NULL);
	pthread_mutex_init(arr[D_TIME], NULL);
	return (TRUE);
}

t_philo	*ft_lst_new(int index)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->index = index;
	if (!ft_init_mutex(new->mutex))
	{
		free(new);
		return (NULL);
	}
	new->fork = new->mutex[F_ONE];
	new->arg = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lst_delete(t_philo *head)
{
	t_philo	*del;

	while (head)
	{
		del = head;
		head = head->next;
		pthread_mutex_destroy(del->fork);
		pthread_mutex_destroy(del->mutex[OVER_EAT]);
		pthread_mutex_destroy(del->mutex[D_TIME]);
		free(del->fork);
		free(del->mutex[OVER_EAT]);
		free(del->mutex[D_TIME]);
		free(del);
	}
}
