/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_pipes_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:21:40 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/06 03:28:41 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_multiple_pipes(int ac, char **av, char **envp, char **path)
{
	t_data	data;
	int		i;

	data.in_fd = ft_first_cmd(av, envp, path);
	i = 2;
	while (++i < ac - 2)
		data.in_fd = ft_mid_cmd(av[i], envp, path, data.in_fd);
	data.last_cmd = av[ac - 2];
	data.out_fd = ft_open_file(av[ac - 1], WRITE);
	if (data.out_fd < 0)
		ft_perror();
	ft_last_cmd(envp, path, data);
}
