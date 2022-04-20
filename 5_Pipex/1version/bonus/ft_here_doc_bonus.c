/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 03:28:46 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/07 02:44:08 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_here_doc(int ac, char **av, char **envp, char **path)
{
	t_data	data;

	if (ac != 6)
		exit(1);
	data.in_fd = ft_read_stdin(av[2]);
}
