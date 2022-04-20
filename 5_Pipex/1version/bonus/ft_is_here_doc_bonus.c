/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:43:09 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/06 03:28:39 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int	ft_is_here_doc(char *first_argument)
{
	char	*tmp;

	tmp = "here_doc";
	while (*tmp && *first_argument)
	{
		if (*tmp != *first_argument)
			return (0);
		tmp++;
		first_argument++;
	}
	if (*tmp != *first_argument)
		return (0);
	return (1);
}
