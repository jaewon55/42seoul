/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_exe_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:57:27 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:09:17 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	ft_create_exe_file(char	*path, int quotes)
{
	int		fd;
	char	*hashbang;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd < 0)
		ft_perror();
	if (!quotes)
	{
		hashbang = "#!/bin/bash\n";
		write(fd, hashbang, ft_strlen(hashbang));
	}
	return (fd);
}
