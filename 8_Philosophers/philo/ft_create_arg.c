/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:43:51 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 01:03:45 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	ft_free_arg(t_philo *head, int idx)
{
	t_philo	*temp;

	temp = head;
	while (temp->index < idx)
	{
		free(temp->arg);
		temp = temp->next;
	}
	ft_lst_delete(head);
	return (FALSE);
}

static t_arg	*ft_new_arg(t_times times, t_philo *philo)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->times = times;
	new->index = philo->index;
	new->mutex[F_ONE] = philo->mutex[F_ONE];
	new->mutex[F_TWO] = philo->mutex[F_TWO];
	new->mutex[OVER_EAT] = philo->mutex[OVER_EAT];
	new->mutex[D_TIME] = philo->mutex[D_TIME];
	new->over_eat = FALSE;
	return (new);
}

int	ft_create_arg(t_times times, t_philo *head)
{
	t_philo			*temp;

	temp = head;
	while (temp)
	{
		temp->arg = ft_new_arg(times, temp);
		if (!temp->arg)
			return (ft_free_arg(head, temp->index));
		temp = temp->next;
	}
	return (TRUE);
}
