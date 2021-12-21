/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:22:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/13 19:15:15 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
char	*get_new_text(char *str)
{
	char	*result;
	size_t	i;

	if (str[0] && ft_strchr(str, '\n'))
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		result = ft_strdup(&str[i + 1]);
	}
	else
		result = NULL;
	free(str);
	return (result);
}

char	*get_one_line(char *str)
{
	char	*result;
	size_t	i;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		result = malloc(sizeof(char) * i + 2);
		if (!result)
			return (NULL);
		result[++i] = '\0';
		while (i)
		{
			i--;
			result[i] = str[i];
		}
	}
	else
		return (ft_strdup(str));
	return (result);
}

char	*read_line(int fd, char *text)
{
	char	*temp;
	ssize_t	buf_size;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buf_size = BUFFER_SIZE;
	while (!ft_strchr(text, '\n') && buf_size != 0)
	{
		buf_size = read(fd, temp, BUFFER_SIZE);
		if (buf_size < 0 || (buf_size == 0 && text && !text[0]))
		{
			free(text);
			text = NULL;
			break ;
		}
		temp[buf_size] = '\0';
		text = ft_strjoin(text, temp);
	}
	free(temp);
	return (text);
}

char	*get_next_line(int fd)
{
	static char		*text[256];
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	text[fd] = read_line(fd, text[fd]);
	if (!(text[fd]))
		return (NULL);
	result = get_one_line(text[fd]);
	text[fd] = get_new_text(text[fd]);
	return (result);
}
