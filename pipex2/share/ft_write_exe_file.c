/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_exe_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:16:40 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 15:54:54 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_write_cmd(char *cmd, int fd)
{
	write(fd, " ", 1);
	write(fd, cmd, ft_strlen(cmd));
	write(fd, " ", 1);
}

void	ft_write_exe_file(int ac, char **av, int fd)
{
	int	i;

	write(fd, "< ", 2);
	write(fd, av[1], ft_strlen(av[1]));
	write(fd, " ", 1);
	i = 1;
	while (++i < ac - 1)
	{
		ft_write_cmd(av[i], fd);
		if (i + 1 < ac - 1)
			write(fd, "|", 1);
		else
			write(fd, "> ", 2);
	}
	write(fd, av[i], ft_strlen(av[i]));
	close(fd);
}
