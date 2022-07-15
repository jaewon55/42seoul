/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 05:25:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/16 01:49:09 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define C_NRML "\033[0m"
# define C_RED  "\033[31m"
# define C_GREN "\033[32m"
# define C_BLUE "\033[34m"
# define C_GRAY "\033[37m"
# define FALSE 0
# define TRUE 1
# define LLONG_MAX 0x7fffffffffffffff
# include <pthread.h>
# include <sys/time.h>

enum e_mutex
{
	F_ONE,
	F_TWO,
	EAT_COUNT,
	D_TIME
};

typedef struct s_times
{
	int				philo_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	pthread_mutex_t	m_run;
	int				*run;
}	t_times;

typedef struct s_arg
{
	t_times			times;
	pthread_mutex_t	mutex[4];
	int				index;
	int				over_eat;
	struct timeval	s_time;
	struct timeval	d_time;
}	t_arg;

typedef struct s_philo
{
	pthread_t		id;
	int				index;
	pthread_mutex_t	fork;
	t_arg			*arg;
	struct s_philo	*next;
}	t_philo;

int		ft_atoi(const char *str);
int		ft_create_arg(t_times times, t_philo *head);
t_philo	*ft_create_philo_list(int philo_count);
void	ft_create_philo(t_philo *head);
int		ft_argument_size_error(void);
int		ft_argument_valid_error(t_times times);
int		ft_share_error(t_times times);
int		ft_create_list_error(t_times times);
int		ft_create_arg_error(t_times times);
t_philo	*ft_lst_new(int index);
void	ft_lst_delete(t_philo *head);

long	ft_get_elapsed_time(struct timeval start);
void	ft_create_watcher(t_philo *head);

int		ft_run_state(t_times time);
void	ft_set_time(pthread_mutex_t mut, struct timeval *time);
void	ft_set_eat_count(t_arg *arg, int *count);

int		ft_take_fork(t_arg *arg, int f_num);
void	ft_start_eating(struct timeval s_time, int idx, int eat_time);
void	ft_start_sleep(struct timeval s_time, int idx, int sleep_time);
void	ft_start_think(struct timeval s_time, int idx);
void	ft_philo_die(struct timeval s_time, int idx);

void	*ft_philo_routine(void *v_arg);
void	*ft_odd_philo_routine(void *v_arg);
void	*ft_watcher_routine(void *v_arg);

#endif
