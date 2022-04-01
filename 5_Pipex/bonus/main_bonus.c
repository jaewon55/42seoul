/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:40:22 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/02 04:53:41 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
int	main(int ac, char **av, char **envp)
{
	char	**path;
	int		in_fd;
	t_data	data;
	int		i;

	if (ac < 5)
		return (1);
	path = ft_get_path(envp);
	if (!path)
		exit(1);
	in_fd = ft_first_cmd(av, envp, path);
	i = 2;
	while (++i < ac - 2)
		in_fd = ft_mid_cmd(av[i], envp, path, in_fd);
	data.in_fd = in_fd;
	data.last_cmd = av[ac - 2];
	data.out_fd = ft_open_file(av[ac - 1], WRITE);
	if (data.out_fd < 0)
		ft_perror();
	ft_last_cmd(envp, path, data);
	while (wait(NULL) > 0)
		;
	exit (0);
}
