/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:39:49 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 15:27:43 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
size_t	ft_list_len(t_list *head)
{
	t_list	*tmp;
	size_t	i;

	tmp = head->next;
	i = 1;
	while (tmp != head)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
