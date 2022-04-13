/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_exe_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:57:27 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 22:51:52 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_create_exe_file(void)
{
	int		fd;
	char	*hashbang;

	hashbang = "#!/bin/bash\n";
	fd = open("/tmp/pipe_exe", O_WRONLY | O_CREAT, 0755);
	if (fd < 0)
		ft_perror();
	write(fd, hashbang, ft_strlen(hashbang));
	return (fd);
}
