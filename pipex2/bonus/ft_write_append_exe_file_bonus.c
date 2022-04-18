/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_append_exe_file_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:13:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 21:45:28 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_write_append_exe_file(char **av, int quotes)
{
	int	fd;

	fd = ft_create_exe_file("/tmp/pipe_exe");
	if (quotes)
		ft_putstr_fd("cat /tmp/pipe_here_doc | ", fd);
	else
		ft_putstr_fd("/tmp/pipe_here_doc", fd);
	ft_putstr_fd(av[3], fd);
	ft_putstr_fd(" | ", fd);
	ft_putstr_fd(av[4], fd);
	ft_putstr_fd(" >> ", fd);
	ft_putstr_fd(av[5], fd);
	close(fd);
}
