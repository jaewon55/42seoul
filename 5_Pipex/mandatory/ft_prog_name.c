/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:05:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 19:55:20 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
char	*ft_prog_name(char *path, char *cmd)
{
	char	*program;
	size_t	len;
	size_t	tmp;

	if (cmd[0] == '/')
		return (cmd);
	len = ft_strlen(path) + ft_strlen(cmd);
	program = malloc(sizeof(char) * (len + 2));
	if (!program)
		exit(1);
	tmp = ft_strlcpy(program, path, len);
	program[tmp] = '/';
	ft_strlcpy(&program[tmp + 1], cmd, len);
	return (program);
}