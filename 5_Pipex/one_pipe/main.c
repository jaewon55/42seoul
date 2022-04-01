/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:24:13 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/01 20:27:08 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
int	main(int ac, char **av, char **envp)
{
	char	**path;
	int		in_fd;

	if (ac != 5)
		return (1);
	path = ft_get_path(envp);
	if (!path)
		exit(1);
	in_fd = ft_first_cmd(av, envp, path);
	ft_last_cmd(av, envp, path, in_fd);
	wait(NULL);
	exit (0);
}
