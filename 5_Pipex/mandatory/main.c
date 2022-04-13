/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:24:13 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 15:04:19 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
int	main(int ac, char **av, char **envp)
{
	char	**path;
	t_data	data;
	int		exit_code;

	if (ac != 5)
		return (1);
	path = ft_get_path(envp);
	if (!path)
		exit(1);
	data.in_fd = ft_first_cmd(av, envp, path);
	data.last_cmd = av[ac - 2];
	data.out_fd = ft_open_file(av[ac - 1], WRITE);
	if (data.out_fd < 0)
		ft_perror();
	exit_code = ft_last_cmd(envp, path, data);
	exit (exit_code);
}
