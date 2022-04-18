/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:11:38 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:08:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static char	*ft_pars_limiter(char *limiter)
{
	char	*result;
	int		i;
	int		j;

	if (limiter[0] != '\'' && limiter[0] != '\"')
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(limiter) - 1));
	i = 1;
	j = 0;
	while (limiter[i])
		result[j++] = limiter[i++];
	result[j - 1] = '\0';
	return (result);
}

int	ft_here_doc(int ac, char **av, char **envp)
{
	int		fd;
	char	*pars_limiter;

	if (ac < 6)
		return (1);
	pars_limiter = ft_pars_limiter(av[2]);
	if (pars_limiter)
	{
		fd = ft_create_exe_file("/tmp/pipe_here_doc", 1);
		ft_quotes_limiter(pars_limiter, fd);
		ft_write_append_exe_file(ac, av, 1);
	}
	else
	{
		fd = ft_create_exe_file("/tmp/pipe_here_doc", 0);
		ft_unquotes_limiter(av[2], fd);
		ft_write_append_exe_file(ac, av, 0);
	}
	return (ft_exec_file(envp));
}
