/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_stdin_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:35:56 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:40:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static void	ft_putstr_except_lf(char *str, int fd)
{
	write(fd, str, ft_strlen(str) - 1);
}

int	ft_write_stdin(char *limiter, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(limiter);
	i = 0;
	while (line)
	{
		i++;
		ft_putstr_except_lf(line, fd);
		free(line);
		line = get_next_line(limiter);
		if (line)
			write(fd, "\n", 1);
	}
	return (i);
}
