/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:13:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/16 01:54:48 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

t_philo	*ft_lst_new(int index)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->index = index;
	pthread_mutex_init(&new->fork, NULL);
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
		pthread_mutex_destroy(&del->fork);
		free(del);
	}
}
