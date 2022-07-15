/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_watcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:21:12 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/15 17:57:25 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_watcher(t_philo *head)
{
	pthread_t	watcher;

	pthread_create(&watcher, NULL, ft_watcher_routine, head);
	pthread_join(watcher, NULL);
}
