/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:05:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 01:04:26 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_fork_mutex(t_philo *philo, pthread_mutex_t *right_fork)
{
	if (philo->index % 2)
	{
		philo->mutex[F_ONE] = philo->fork;
		philo->mutex[F_TWO] = right_fork;
		return ;
	}
	philo->mutex[F_ONE] = right_fork;
	philo->mutex[F_TWO] = philo->fork;
}

static void	ft_sort_fork(t_philo *head)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	temp_mutex;
	t_philo			*temp;

	temp = head->next;
	right_fork = head->fork;
	while (temp)
	{
		ft_init_fork_mutex(temp, right_fork);
		right_fork = temp->fork;
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	if (temp)
		head->mutex[F_TWO] = temp->fork;
	else
		head->mutex[F_TWO] = &temp_mutex;
}

t_philo	*ft_create_philo_list(int philo_count)
{
	t_philo	*head;
	t_philo	*temp;
	int		i;

	head = ft_lst_new(1);
	temp = head;
	i = 1;
	while (1)
	{
		if (!temp)
		{
			ft_lst_delete(head);
			return (NULL);
		}
		if (++i > philo_count)
			break ;
		temp->next = ft_lst_new(i);
		temp = temp->next;
	}
	ft_sort_fork(head);
	return (head);
}
