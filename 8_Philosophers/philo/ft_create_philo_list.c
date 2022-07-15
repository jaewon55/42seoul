/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:05:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/07/15 18:01:28 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	return (head);
}
