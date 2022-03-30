/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:29:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:22:57 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdlib.h>
static void	ft_set_child_fd(t_fildes fildes)
{
	close(fildes.pipe_fd[0]);
	if (dup2(fildes.pipe_fd[1], 1) < 0 || dup2(fildes.in_fd, 0) < 0)
		ft_perror();
	close(fildes.pipe_fd[1]);
	close(fildes.in_fd);
}

static void	ft_child_proc(t_fildes fildes, char *cmd, char **envp, char **path)
{
	int		i;
	char	**av;
	char	*program;

	av = ft_split(cmd, ' ');
	if (!av)
		ft_perror();
	i = 0;
	while (path[i])
	{
		program = ft_prog_name(path[i], av[0]);
		if (!access(program, X_OK))
			break ;
		i++;
		free(program);
	}
	if (!path[i])
	{
		ft_printf("command not found: %s\n", cmd);
		exit(127);
	}
	ft_set_child_fd(fildes);
	execve(program, av, envp);
	exit(1);
}

int	ft_first_cmd(char **av, char **envp, char **path)
{
	t_fildes	fildes;
	pid_t		pid;

	fildes = ft_open_fd(av[1]);
	if (fildes.in_fd < 0)
	{
		close(fildes.pipe_fd[1]);
		return (fildes.pipe_fd[0]);
	}
	pid = fork();
	if (pid < 0)
		ft_perror();
	else if (pid == 0)
		ft_child_proc(fildes, av[2], envp, path);
	close(fildes.pipe_fd[1]);
	close(fildes.in_fd);
	return (fildes.pipe_fd[0]);
}
