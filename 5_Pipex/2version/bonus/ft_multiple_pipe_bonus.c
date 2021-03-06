/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_pipe_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:10:18 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:09:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_multiple_pipe(int ac, char **av, char **envp)
{
	int	fd;

	fd = ft_create_exe_file("/tmp/pipe_exe", 0);
	ft_write_exe_file(ac, av, fd);
	return (ft_exec_file(envp));
}
