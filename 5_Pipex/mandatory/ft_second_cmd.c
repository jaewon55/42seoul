/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:36:50 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:23:24 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
static	void	ft_set_child_fd(char *out_file, int in_fd)
{
	int	out_fd;

	out_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		ft_perror();
	if (dup2(out_fd, 1) < 0 || dup2(in_fd, 0) < 0)
		ft_perror();
	close(out_fd);
	close(in_fd);
}

static void	ft_child_proc(int in_fd, char **av, char **envp, char **path)
{
	int			i;
	char		**args;
	char		*program;

	args = ft_split(av[3], ' ');
	if (!args)
		ft_perror();
	i = 0;
	while (path[i])
	{
		program = ft_prog_name(path[i], args[0]);
		if (!access(program, X_OK))
			break ;
		i++;
		free(program);
	}
	if (!path[i])
	{
		ft_printf("command not found: %s\n", av[3]);
		exit(127);
	}
	ft_set_child_fd(av[4], in_fd);
	execve(program, args, envp);
	exit(1);
}

void	ft_second_cmd(char **av, char **envp, char **path, int in_fd)
{
	pid_t		pid;
	int			status;

	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (pid == 0)
		ft_child_proc(in_fd, av, envp, path);
	if (waitpid(pid, &status, 0) < 0)
		ft_perror();
	if (WIFEXITED(status) && WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
	close(in_fd);
}
