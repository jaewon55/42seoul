/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:19:32 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 18:19:32 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
t_list	*ft_parsing(int ac, char *av[])
{
	t_list	*head;
	int		i;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		head = ft_split_list(av[i], head);
		if (!head)
			return (NULL);
	}
	return (head);
}
