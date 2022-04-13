/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:45:20 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 20:12:42 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int	main(int ac, char **av, char **envp)
{
	int	fd;

	if (ac != 5)
		return (1);
	fd = ft_create_exe_file();
	ft_write_exe_file(ac, av, fd);
	return (ft_exec_file(envp));
}
