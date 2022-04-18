/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:11:38 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 21:42:29 by jaewchoi         ###   ########.fr       */
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
	result[j] = '\0';
	return (result);
}

int	ft_here_doc(int ac, char **av, char **envp)
{
	int		fd;
	char	*pars_limiter;

	if (ac != 6)
		return (1);
	fd = ft_create_exe_file("/tmp/pipe_here_doc");
	pars_limiter = ft_pars_limiter(av[1]);
	if (pars_limiter)
	{
		ft_quotes_limiter(pars_limiter, fd);
		ft_write_append_exe_file(av, 1);
	}
	else
	{
		ft_unquotes_limiter(av[1], fd);
		ft_write_append_exe_file(av, 0);
	}
	return (ft_exec_file(envp));
}
