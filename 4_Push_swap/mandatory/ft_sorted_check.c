/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:01:58 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/19 18:06:48 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_sorted_check(t_list *head)
{
	t_list	*tmp;

	tmp = head->next;
	while (tmp != head)
	{
		if (tmp->pre->content > tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
