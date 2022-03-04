/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:39:27 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/04 21:04:44 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static char	*read_line(char *text)
{
	char	*tmp;
	int		buf_size;

	tmp = malloc(sizeof(char) * (11));
	if (!tmp)
	{
		free(text);
		return (NULL);
	}
	buf_size = 10;
	while (text && buf_size)
	{
		buf_size = read(0, tmp, 10);
		if (buf_size < 0)
		{
			free(text);
			text = NULL;
			break ;
		}
		tmp[buf_size] = '\0';
		text = ft_strjoin(text, tmp, buf_size);
	}
	free(tmp);
	return (text);
}

char	*get_next_line(void)
{
	char	*text;

	text = ft_strdup("");
	if (!text)
		return (NULL);
	return (read_line(text));
}
