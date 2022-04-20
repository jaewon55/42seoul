/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:11:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 15:46:04 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <sys/wait.h>
static void	ft_set_child_fd(int out_fd, int in_fd)
{
	if (dup2(out_fd, STDOUT) < 0 || dup2(in_fd, STDIN) < 0)
		ft_perror();
	close(out_fd);
	close(in_fd);
}

static void	ft_child_proc(t_data data, char **envp, char **path)
{
	char	*program;
	char	**args;

	args = ft_split(data.last_cmd, ' ');
	if (!args)
		ft_perror();
	program = ft_prog_name(path, args[0]);
	if (!program)
	{
		dup2(STDERR, STDOUT);
		ft_printf("command not found: %s\n", args[0]);
		exit(127);
	}
	ft_set_child_fd(data.out_fd, data.in_fd);
	if (execve(program, args, envp) < 0)
		ft_perror();
}

int	ft_last_cmd(char **envp, char **path, t_data data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (pid == 0)
		ft_child_proc(data, envp, path);
	if (waitpid(pid, &status, 0) < 0)
		ft_perror();
	close(data.in_fd);
	while (wait(NULL) > 0)
		;
	return (WEXITSTATUS(status));
}
