/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:17:55 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 15:56:14 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		ft_perror();
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*get_new_text(char *str)
{
	char	*result;
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	result = ft_strdup(&str[i + 1]);
	free(str);
	return (result);
}

static char	*get_one_line(char *str)
{
	char	*result;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * i + 2);
	if (!result)
		ft_perror();
	result[++i] = '\0';
	while (i)
	{
		i--;
		result[i] = str[i];
	}
	return (result);
}

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
	return (result);
}

char	*get_next_line(char *limiter)
{
	static char	*text;
	char		*result;
	char		buf[1024];
	int			buf_size;

	if (!text)
		text = ft_strdup("");
	while (!ft_strchr(text, '\n'))
	{
		buf_size = read(0, buf, 1000);
		if (buf_size < 0)
			ft_perror();
		buf[buf_size] = '\0';
		text = gnl_str_join(text, buf);
	}
	result = get_one_line(text);
	if (ft_is_limiter(limiter, result))
	{
		free(result);
		free(text);
		return (NULL);
	}
	text = get_new_text(text);
	return (result);
}
