/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:34:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 05:36:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
t_fildes	ft_open_fd(char *infile)
{
	t_fildes	fildes;

	fildes.file_fd = open(infile, O_RDONLY);
	if (fildes.file_fd < 0)
		ft_perror("open error");
	if (pipe(fildes.pipe_fd[2]) < 0)
		ft_perror("pipe error");
	return (fildes);
}