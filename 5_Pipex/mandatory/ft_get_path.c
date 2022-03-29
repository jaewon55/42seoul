/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:14:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 18:21:03 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
static int	ft_is_path(char *str)
{
	char	*tmp;

	tmp = "PATH";
	while (*tmp)
	{
		if (*tmp != *str)
			return (0);
		tmp++;
		str++;
	}
	return (1);
}

char	**ft_get_path(char *envp[])
{
	char	**result;
	int		i;

	result = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_is_path(envp[i]))
		{
			result = ft_split(&envp[i][5], ':');
			break ;
		}
		i++;
	}
	return (result);
}