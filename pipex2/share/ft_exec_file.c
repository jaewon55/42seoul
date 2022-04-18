/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:50:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 17:14:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <sys/wait.h>

static void	ft_child_proc(char **envp)
{
	char *const	args[2] = {"/tmp/piep_exe", NULL};

	if (execve("/tmp/pipe_exe", args, envp) < 0)
		ft_perror();
}

int	ft_exec_file(char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (!pid)
		ft_child_proc(envp);
	wait(&status);
	unlink("/tmp/pipe_exe");
	unlink("/tmp/pipe_here_doc");
	return (WEXITSTATUS(status));
}
