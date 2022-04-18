/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_stdin_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:35:56 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 21:46:18 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
static int	ft_is_limiter(char *limiter, char *input)
{
	int	i;

	i = 0;
	while (limiter[i] && input[i])
	{
		if (limiter[i] != input[i])
			return (0);
		i++;
	}
	if (!limiter[i] && input[i] == '\n')
		return (1);
	return (0);
}

void	ft_write_stdin(char *limiter, int fd)
{
	char	*line;

	line = get_next_line();
	while (!ft_is_limiter(limiter, line))
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line();
	}
}
