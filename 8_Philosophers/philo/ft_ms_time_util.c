/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_time_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:37:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/15 19:14:53 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_elapsed_time(struct timeval start)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000 \
	+ (end.tv_usec - start.tv_usec) / 1000);
}
