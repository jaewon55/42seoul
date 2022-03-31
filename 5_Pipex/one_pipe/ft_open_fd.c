/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:34:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:21:45 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
t_fildes	ft_open_fd(char *infile)
{
	t_fildes	fildes;

	if (infile)
		fildes.in_fd = open(infile, O_RDONLY);
	if (pipe(fildes.pipe_fd) < 0)
		ft_perror();
	return (fildes);
}
