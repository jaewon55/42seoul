/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:44:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/07 17:05:26 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <sys/wait.h>
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

static void	ft_child_proc(int *fd, char *limiter)
{
	char	buf[1024];
	char	*pars_limiter;

	close(fd[READ]);
	pars_limiter = ft_pars_limiter(limiter);
	if (pars_limiter)
		ft_quotes_limiter(fd[WRITE], pars_limiter);
	else
		ft_unquotes_limiter(fd[WRITE], limiter);
}

int	ft_read_stdin(char *limiter)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) < 0)
		ft_perror();
	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (pid == 0)
		ft_child_proc(fd, limiter);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status))
		ft_perror();
	close(fd[WRITE]);
	return (fd[READ]);
}
