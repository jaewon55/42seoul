/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:55:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/22 16:03:43 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	add_list(t_list *head, int num)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return (FALSE);
	last = head->pre;
	last->next = new;
	new->pre = last;
	new->next = head;
	head->pre = new;
	new->content = num;
	return (TRUE);
}

static int	check_duplicates(t_list *head, int num)
{
	t_list	*idx_node;

	if (head->content == num)
		return (FALSE);
	idx_node = head->next;
	while (idx_node != head)
	{
		if (idx_node->content == num)
			return (FALSE);
		idx_node = idx_node->next;
	}
	return (TRUE);
}

static ssize_t	get_integer(char *str, size_t *i)
{
	ssize_t	num;
	int		minus;

	minus = 1;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		minus = -1;
		(*i)++;
	}
	if (!str[*i] || !(str[*i] >= '0' && str[*i] <= '9'))
		return (UINT_MAX);
	num = 0;
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		num *= 10;
		num += str[*i] - '0';
		(*i)++;
	}
	return (num * minus);
}

int	ft_split_num(char *str, t_list *head)
{
	size_t	i;
	ssize_t	num;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		num = get_integer(str, &i);
		if (num < 0 && (INT_MIN > num))
			return (ft_list_del(head));
		else if (num >= 0 && (INT_MAX < num))
			return (ft_list_del(head));
		else if (!check_duplicates(head, num))
			return (ft_list_del(head));
		if (!add_list(head, num))
			return (ft_list_del(head));
	}
	return (TRUE);
}
