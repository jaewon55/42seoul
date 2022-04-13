/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:36:46 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 14:38:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
static void	ft_set_child_fd(t_data data)
{
	close(data.pipe_fd[READ]);
	if (dup2(data.pipe_fd[WRITE], STDOUT) < 0 || dup2(data.in_fd, STDIN) < 0)
		ft_perror();
	close(data.pipe_fd[WRITE]);
	close(data.in_fd);
}

static void	ft_child_proc(t_data data, char *cmd, char **envp, char **path)
{
	char	*program;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		ft_perror();
	program = ft_prog_name(path, args[0]);
	if (!program)
	{
		dup2(STDERR, STDOUT);
		ft_printf("command not found: %s\n", args[0]);
		exit(127);
	}
	ft_set_child_fd(data);
	if (execve(program, args, envp) < 0)
		ft_perror();
}

int	ft_mid_cmd(char *cmd, char **envp, char **path, int in_fd)
{
	t_data	data;
	pid_t	pid;

	data.in_fd = in_fd;
	if (pipe(data.pipe_fd) < 0)
		ft_perror();
	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (pid == 0)
		ft_child_proc(data, cmd, envp, path);
	close(data.pipe_fd[WRITE]);
	close(data.in_fd);
	return (data.pipe_fd[READ]);
}
