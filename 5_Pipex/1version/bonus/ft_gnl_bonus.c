/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:54:36 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/08 01:53:15 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
static char	*gnl_str_join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		ft_perror();
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return(result);
}

char	*get_next_line(void)
{
	char	*result;
	char	buf[1024];
	int		buf_size;

	result = malloc(sizeof(char) * 1);
	if (!result)
		ft_perror();
	result[0] = '\0';
	while (!ft_strchr(result, '\n'))
	{
		buf_size = read(0, buf, 1000);
		if (buf_size < 0)
			ft_perror();
		buf[buf_size] = '\0';
		result = gnl_str_join(result, buf);
	}
	free(buf);
	return (result);
}
