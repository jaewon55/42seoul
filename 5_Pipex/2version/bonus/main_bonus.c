/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:00:58 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 15:57:02 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac < 5)
		return (1);
	if (ft_is_here_doc(av[1]))
		return (ft_here_doc(ac, av, envp));
	else
		return (ft_multiple_pipe(ac, av, envp));
}
