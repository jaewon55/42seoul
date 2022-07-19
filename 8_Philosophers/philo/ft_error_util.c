/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:20:40 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/19 01:05:21 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

int	ft_argument_size_error(void)
{
	printf("%splease 5 or 6 arguments%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_argument_valid_error(t_times times)
{
	if (times.philo_count <= 0 || times.die_time < 0 \
	|| times.eat_time < 0 || times.sleep_time < 0 || times.eat_count < 0)
		printf("%splease valid arguments%s\n", C_RED, C_NRML);
	else
		printf("%smalloc fail%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_share_error(t_times times)
{
	pthread_mutex_destroy(times.m_run);
	free(times.run);
	printf("%sshare initialization fail%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_create_list_error(t_times times)
{
	pthread_mutex_destroy(times.m_run);
	free(times.run);
	printf("%screate philo list fail%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_create_arg_error(t_times times)
{
	pthread_mutex_destroy(times.m_run);
	free(times.run);
	printf("%screate thread argument fail%s\n", C_RED, C_NRML);
	return (1);
}
