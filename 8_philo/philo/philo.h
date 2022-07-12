/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:25:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/12 11:06:47 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define C_NRML "\033[0m"
# define C_RED  "\033[31m"
# define C_GREN "\033[32m"
# define C_BLUE "\033[34m"
# define C_GRAY "\033[37m"
#include <pthread.h>
# define FALSE 0
# define TRUE 1
# define LLONG_MAX 0x7fffffffffffffff

enum e_status
{
	THINK,
	EAT,
	SLEEP,
	DIE
}

typedef struct s_times
{
	int	philo_count;
	int	die_time;
	int	eat_time;
	int sleep_time;
	int eat_count;
}	t_times;

typedef struct s_philo
{
	pthread_t		id;
	int				num;
	struct s_thread	*next;
}	t_philo;

typedef struct s_share
{
	int	*state;
	int	*fork;
	int	start;
	pthread_mutex_t	m_state;
	pthread_mutex_t m_fork;
}	t_share;

int		ft_atoi(const char *str);
void	*ft_start_routine(void *arg);

#endif
