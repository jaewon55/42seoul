/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:31:54 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 12:25:02 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>

static char	*ft_read_map(int fd)
{
	char	buf[1024];
	ssize_t	buf_size;
	char	*temp;
	char	*read_map;

	read_map = ft_calloc(1, sizeof(char));
	if (!read_map)
		ft_error(NULL);
	buf_size = 1;
	while (buf_size > 0)
	{
		buf_size = read(fd, buf, 512);
		if (buf_size < 0)
			ft_error(NULL);
		else if (buf_size == 0)
			break ;
		buf[buf_size] = '\0';
		temp = read_map;
		read_map = ft_strjoin(temp, buf);
		if (!read_map)
			ft_error(NULL);
		free(temp);
	}
	return (read_map);
}

char	**ft_parse_map(char *file)
{
	int		fd;
	char	*read_map;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	read_map = ft_read_map(fd);
	close(fd);
	map = ft_split(read_map, '\n');
	if (!map)
		ft_error(NULL);
	free(read_map);
	return (map);
}
