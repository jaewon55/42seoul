/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:40:22 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 15:50:48 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
int	main(int ac, char **av, char **envp)
{
	char	**path;

	if (ac < 5)
		return (1);
	path = ft_get_path(envp);
	if (!path)
		exit(1);
	if (ft_is_here_doc(av[1]))
		ft_here_doc(ac, av, envp, path);
	else
		ft_multiple_pipes(ac, av, envp, path);
	exit (0);
}
