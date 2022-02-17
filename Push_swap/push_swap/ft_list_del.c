/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:09:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/16 20:46:10 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_list_del(t_list *head)
{
	t_list	*idx_node;
	t_list	*tmp_node;

	if (!head)
		return (FALSE);
	idx_node = head->next;
	while (idx_node != head)
	{
		tmp_node = idx_node;
		idx_node = idx_node->next;
		free(tmp_node);
	}
	free(head);
	return (FALSE);
}
