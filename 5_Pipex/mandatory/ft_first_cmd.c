/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:29:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 20:01:02 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdlib.h>
static void	ft_set_child_fd(t_fildes fildes)
{
	close(fildes.pipe_fd[0]);
	if (dup2(fildes.pipe_fd[1], 1) < 0 || dup2(fildes.in_fd, 0) < 0)
		ft_perror("dup2 error");
	close(fildes.pipe_fd[1]);
	close(fildes.in_fd);
}

static void ft_child_proc(t_fildes fildes, char *cmd, char **envp, char **path)
{
	int		i;
	char	**av;
	char	*program;

	av = ft_split(cmd, ' ');
	if (!av)
		ft_perror("ft_split error");
	ft_set_child_fd(fildes);
	i = 0;
	while (path[i])
	{
		program = ft_prog_name(path[i++], av[0]);
		execve(program, av, envp);
		free(program);
	}
	exit(1);
}

int	ft_first_cmd(char **av, char **envp, char **path)
{
	t_fildes	fildes;
	pid_t		pid;
	int			status;

	fildes = ft_open_fd(av[1]);
	pid = fork();
	if (pid < 0)
		ft_perror("for error");
	else if (pid == 0)
		ft_child_proc(fildes, av[2], envp, path);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status))
		exit(1);
	close(fildes.pipe_fd[1]);
	close(fildes.in_fd);
	return (fildes.pipe_fd[0]);
}