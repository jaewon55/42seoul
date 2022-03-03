/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:25:45 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 19:04:22 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	list_idx_initialize(t_list *head)
{
	t_list	*tmp;
	size_t	i;

	tmp = head->next;
	head->idx = 0;
	i = 1;
	while (tmp != head)
	{
		tmp->idx = i++;
		tmp = tmp->next;
	}
}

static int	ft_head_content(char *av[], int minus, ssize_t tmp, t_list *head)
{
	size_t	i;

	i = 0;
	while (av[1][i] && av[1][i] == ' ')
		i++;
	if (av[1][i] == '+')
		i++;
	else if (av[1][i] == '-')
	{
		minus = -1;
		i++;
	}
	if (!av[1][i] || !(av[1][i] >= '0' && av[1][i] <= '9'))
		return (FALSE);
	while (av[1][i] && (av[1][i] >= '0' && av[1][i] <= '9'))
	{
		tmp *= 10;
		tmp += av[1][i++] - '0';
	}
	if ((minus < 0 && tmp > (ssize_t)INT_MAX + 1) || (minus > 0 && tmp > INT_MAX))
		return (FALSE);
	head->content = (int)(tmp * minus);
	av[1] = &(av[1][i]);
	return (TRUE);
}

t_list	*ft_parsing_av(int ac, char *av[])
{
	t_list	*head;
	int		i;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (!ft_head_content(av, 1, 0, head))
	{
		free(head);
		return (NULL);
	}
	head->next = head;
	head->pre = head;
	i = 0;
	while (++i < ac)
		if (!ft_split_num(av[i], head))
			return (NULL);
	list_idx_initialize(head);
	return (head);
}
