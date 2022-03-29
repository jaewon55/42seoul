/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:29:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 06:49:36 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
static void	ft_set_child_fd(t_fildes fildes)
{
	close(fildes.pipe_fd[0]);
	if (dup2(fildes.pipe_fd[1], 1) < 0 || dup2(fildes.file_fd, 0) < 0)
		ft_perror("dup2 error");
	close(fildes.pipe_fd[1]);
	close(fildes.file_fd);
}

static char	*ft_prog_name(char *path, char *cmd)
{
	char	*program;
	size_t	len;
	size_t	tmp;

	if (cmd[0] == '/')
		return (cmd);
	len = ft_strlen(path) + ft_strlen(cmd);
	program = malloc(sizeof(char) * (len + 2));
	if (!program)
		exit(1);
	tmp = ft_strlcpy(program, path, len);
	program[tmp] = '/';
	ft_strlcpy(program[tmp + 1], cmd, len);
	return (program);
}

static void ft_child_proc(t_fildes fildes, char *cmd, char **envp, char **path)
{
	int		i;
	char	**av;
	char	*program;

	av = ft_split(cmd, ' ');
	if (!av)
		exit(1);
	ft_set_child_fd(fildes);
	i = 0;
	while (path[i])
	{
		program = ft_prog_name(path[i], cmd);
		execve(program, av, envp);
		free(program);
	}
	exit(1);
}

int	ft_first_cmd(char **av, char **envp, char **path)
{
	t_fildes	fildes;
	int			status;
	pid_t		pid;
	int			i;

	fildes = ft_open_fd(av[1]);
	pid = fork();
	if (pid < 0)
		ft_perror("for error");
	else if (pid == 0)
		ft_child_proc(fildes, av[2], envp, path);
	waitpid(pid, status, 0);
	close(fildes.pipe_fd[1]);
	if (WEXITSTATUS(status))
		exit(1);
	close(fildes.file_fd);
	return (fildes.pipe_fd[0]);
}