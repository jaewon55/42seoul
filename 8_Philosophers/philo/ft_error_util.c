/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:20:40 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/15 18:04:33 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	ft_argument_size_error(void)
{
	printf("%splease 5 or 6 arguments%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_argument_valid_error(t_times times)
{
	pthread_mutex_destroy(&times.m_run);
	printf("%splease valid arguments%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_share_error(t_times times)
{
	pthread_mutex_destroy(&times.m_run);
	printf("%sshare initialization fail%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_create_list_error(t_times times)
{
	pthread_mutex_destroy(&times.m_run);
	printf("%screate philo list fail%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_create_arg_error(t_times times)
{
	pthread_mutex_destroy(&times.m_run);
	printf("%screate thread argument fail%s\n", C_RED, C_NRML);
	return (1);
}
