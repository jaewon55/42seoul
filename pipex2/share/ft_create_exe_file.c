/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_exe_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:57:27 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/15 14:12:04 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
int	ft_create_exe_file(void)
{
	int		fd;
	char	*hashbang;

	hashbang = "#!/bin/bash\n";
	fd = open("/tmp/pipe_exe", O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd < 0)
		ft_perror();
	write(fd, hashbang, ft_strlen(hashbang));
	return (fd);
}
