/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:24:13 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:23:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
int	main(int ac, char **av, char **envp)
{
	char	**path;
	int		second_input_fd;
	int		i;

	if (ac != 5)
		return (1);
	path = ft_get_path(envp);
	if (!path)
		exit(1);
	second_input_fd = ft_first_cmd(av, envp, path);
	ft_second_cmd(av, envp, path, second_input_fd);
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	return (0);
}
