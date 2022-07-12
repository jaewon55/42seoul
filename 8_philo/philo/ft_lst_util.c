/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:13:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 08:43:06 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

t_philo	*ft_lst_new(int num, void *arg)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	pthread_create(&new->id, NULL, ft_start_routine, arg);
	// pthread_detach(new->id);
	new->num = num;
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
		free(del);
	}
}
