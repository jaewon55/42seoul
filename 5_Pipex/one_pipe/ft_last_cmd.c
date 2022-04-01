/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:11:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/01 20:25:44 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <sys/wait.h>
static void	ft_set_child_fd(char *out_file, int in_fd)
{
	int	out_fd;

	out_fd = ft_open_file(out_file, WRITE);
	if (out_fd < 0)
		exit(1);
	if (dup2(out_fd, STDOUT) < 0 || dup2(in_fd, STDIN) < 0)
		ft_perror();
	close(out_fd);
	close(in_fd);
}

static void	ft_child_proc(int in_fd, char **av, char **envp, char **path)
{
	char	*program;
	char	**args;

	args = ft_split(av[3], ' ');
	if (!args)
		ft_perror();
	program = ft_prog_name(path, args[0]);
	if (!program)
	{
		dup2(2, 1);
		ft_printf("command not found: %s\n", args[0]);
		exit(1);
	}
	ft_set_child_fd(av[4], in_fd);
	if (execve(program, args, envp) < 0)
		ft_perror();
}

void	ft_last_cmd(char **av, char **envp, char **path, int in_fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (pid == 0)
		ft_child_proc(in_fd, av, envp, path);
	if (waitpid(pid, &status, 0) < 0)
		ft_perror();
	close(in_fd);
}
