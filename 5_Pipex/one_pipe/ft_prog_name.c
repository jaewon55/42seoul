/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:05:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/01 20:05:40 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
static char	*ft_set_name(char *path, char *cmd)
{
	char	*program;
	size_t	len;
	size_t	tmp;

	len = ft_strlen(path) + ft_strlen(cmd);
	program = malloc(sizeof(char) * (len + 2));
	if (!program)
		exit(1);
	tmp = ft_strlcpy(program, path, len);
	program[tmp] = '/';
	ft_strlcpy(&program[tmp + 1], cmd, len);
	return (program);
}

char	*ft_prog_name(char **path, char *cmd)
{
	int		i;
	char	*program;

	if (cmd[0] == '/' || cmd[0] == '.' || !access(cmd, X_OK))
		return (cmd);
	i = 0;
	while (path[i])
	{
		program = ft_set_name(path[i], cmd);
		if (!access(program, X_OK))
			return (program);
		i++;
		free(program);
	}
	return (NULL);
}
