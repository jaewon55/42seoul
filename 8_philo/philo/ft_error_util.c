/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:20:40 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 09:34:31 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int ft_argument_size_error(void)
{
	printf("%splease 5 or 6 arguments%s\n", C_RED ,C_NRML);
	return (1);
}

int ft_argument_valid_error(void)
{
	printf("%splease valid arguments%s\n", C_RED, C_NRML);
	return (1);
}

int	ft_share_error(void)
{
	printf("%sshare initialization fail%s\n", C_RED, C_NRML);
	return (1);
}

int ft_create_thread_error(t_share *share)
{
	free(share->state);
	free(share->fork);
	pthread_mutex_destroy(&share->m_state);
	pthread_mutex_destroy(&share->m_fork);
	free(share);
	printf("%screate thread fail%s\n", C_RED, C_NRML);
	return (1);
}
