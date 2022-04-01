/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:16:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/01 20:25:05 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
static t_data	ft_set_fd(char *file)
{
	t_data	data;

	data.in_fd = ft_open_file(file, READ);
	pipe(data.pipe_fd);
	if (data.in_fd < 0)
	{
		close(data.pipe_fd[WRITE]);
		return (data);
	}
	return (data);
}

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

	data.args = ft_split(cmd, ' ');
	if (!data.args)
		ft_perror();
	program = ft_prog_name(path, data.args[0]);
	if (!program)
	{
		dup2(2, 1);
		ft_printf("command not found: %s\n", data.args[0]);
		exit(1);
	}
	ft_set_child_fd(data);
	if (execve(program, data.args, envp) < 0)
		ft_perror();
}

int	ft_first_cmd(char **av, char **envp, char **path)
{
	t_data	data;
	pid_t	pid;

	data = ft_set_fd(av[1]);
	if (data.in_fd < 0)
		return (data.pipe_fd[READ]);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
		ft_child_proc(data, av[2], envp, path);
	close(data.pipe_fd[WRITE]);
	close(data.in_fd);
	return (data.pipe_fd[READ]);
}
