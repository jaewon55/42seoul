/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:19:49 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 21:19:49 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
void	*ft_list_del(t_list *head)
{
	t_list	*idx_node;
	t_list	*tmp_node;

	if (!head)
		return (NULL);
	idx_node = head->next;
	while (idx_node != head)
	{
		tmp_node = idx_node;
		idx_node = idx_node->next;
		free(tmp_node);
	}
	free(head);
	return (NULL);
}
