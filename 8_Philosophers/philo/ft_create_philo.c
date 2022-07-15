/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:07:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/16 02:17:30 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philo(t_philo *head)
{
	while (head)
	{
		if (head->index % 2)
			pthread_create(&head->id, NULL, ft_philo_routine, head->arg);
		else
			pthread_create(&head->id, NULL, ft_odd_philo_routine, head->arg);
		head = head->next;
	}
}
