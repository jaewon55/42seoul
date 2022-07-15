/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:43:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/16 01:26:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	ft_free_arg(t_philo *head, int idx)
{
	t_philo	*temp;
	t_philo	*del;

	temp = head->next;
	while (temp)
	{
		pthread_mutex_destroy(&temp->fork);
		if (temp->index < idx)
		{
			pthread_mutex_destroy(&temp->arg->mutex[EAT_COUNT]);
			pthread_mutex_destroy(&temp->arg->mutex[D_TIME]);
			free(temp->arg);
		}
		del = temp;
		temp = temp->next;
		free(del);
	}
	free(head);
	return (1);
}

static t_arg	*ft_new_arg(t_times times, int index)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->index = index;
	new->times = times;
	pthread_mutex_init(&new->mutex[EAT_COUNT], NULL);
	pthread_mutex_init(&new->mutex[D_TIME], NULL);
	new->over_eat = FALSE;
	return (new);
}

static void	ft_fork_init(t_arg *arg, pthread_mutex_t l, pthread_mutex_t r)
{
	if (arg->index % 2)
	{
		arg->mutex[F_ONE] = l;
		arg->mutex[F_TWO] = r;
	}
	else
	{
		arg->mutex[F_ONE] = r;
		arg->mutex[F_TWO] = l;
	}
}

int	ft_create_arg(t_times times, t_philo *head)
{
	t_philo			*temp;
	pthread_mutex_t	right_fork;

	temp = head->next;
	right_fork = head->fork;
	while (temp)
	{
		temp->arg = ft_new_arg(times, temp->index);
		if (!temp->arg)
			return (ft_free_arg(head, temp->index));
		ft_fork_init(temp->arg, temp->fork, right_fork);
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	head->arg = ft_new_arg(times, head->index);
	if (!head->arg)
		return (ft_free_arg(head, times.philo_count + 1));
	head->arg->mutex[F_ONE] = head->fork;
	if (temp)
		head->arg->mutex[F_TWO] = temp->fork;
	return (TRUE);
}
