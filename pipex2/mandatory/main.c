/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:45:20 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 18:06:17 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int	main(int ac, char **av, char **envp)
{
	int	fd;

	if (ac != 5)
		return (1);
	fd = ft_create_exe_file("/tmp/pipe_exe");
	ft_write_exe_file(ac, av, fd);
	return (ft_exec_file(envp));
}
