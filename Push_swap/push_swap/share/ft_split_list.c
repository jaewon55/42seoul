/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:09:02 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 19:37:13 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>
#include <limits.h>
static int	check_duplicates(t_list *head, int num)
{
	t_list	*idx_node;

	if (head->content == num)
		return (0);
	idx_node = head->next;
	while (idx_node != head)
	{
		if (idx_node->content == num)
			return (0);
		idx_node = idx_node->next;
	}
	return (1);
}

static char	*node_content(char *str, t_list *head)
{
	ssize_t	tmp;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	tmp = ft_itoa(&str);
	if (tmp > INT_MAX || !check_duplicates(head, tmp))
	{
		free(new);
		return (NULL);
	}
	new->content = (int)tmp;
	new->next = head;
	new->pre = head->pre;
	head->pre->next = new;
	head->pre = new;
	while (*str && *str == ' ')
		str++;
	return (str);
}

static char	*head_content(char *str, t_list *head)
{
	ssize_t	tmp;

	tmp = ft_itoa(&str);
	if (tmp > INT_MAX)
		return (NULL);
	head->content = (int)tmp;
	head->next = head;
	head->pre = head;
	while (*str && *str == ' ')
		str++;
	return (str);
}

t_list	*ft_split_list(char *str, t_list *head)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return ((t_list *)ft_list_del(head));
	if (!head->next)
		str = head_content(&str[i], head);
	if (!str)
		return ((t_list *)ft_list_del(head));
	while (str[0])
	{
		if (str[0] != ' ' && str[0] != '+' && str[0] != '-'\
		&& !(str[0] >= '0' && str[0] <= '9'))
			return ((t_list *)ft_list_del(head));
		str = node_content(str, head);
		if (!str)
			return ((t_list *)ft_list_del(head));
	}
	return (head);
}
