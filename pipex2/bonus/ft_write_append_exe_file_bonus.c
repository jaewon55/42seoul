/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_append_exe_file_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:13:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:09:57 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_write_append_exe_file(int ac, char **av, int quotes)
{
	int	fd;
	int	i;

	fd = ft_create_exe_file("/tmp/pipe_exe", 0);
	if (quotes)
		ft_putstr_fd("cat /tmp/pipe_here_doc | ", fd);
	else
		ft_putstr_fd("/tmp/pipe_here_doc | ", fd);
	i = 2;
	while (++i < ac - 1)
	{
		ft_putstr_fd(av[i], fd);
		if (i + 1 < ac - 1)
			ft_putstr_fd(" | ", fd);
		else
			ft_putstr_fd(" >> ", fd);
	}
	ft_putstr_fd(av[i], fd);
	close(fd);
}
