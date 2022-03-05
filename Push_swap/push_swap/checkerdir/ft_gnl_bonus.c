/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 01:32:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 20:47:36 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static char	*get_one_line(char **text)
{
	char	*line;
	int		i;
	int		tmp;

	i = 0;
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	if ((*text)[i] == '\0')
		return (NULL);
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	tmp = i;
	line[i] = '\0';
	while (--i >= 0)
		line[i] = (*text)[i];
	while ((*text)[tmp])
		(*text)[++i] = (*text)[++tmp];
	return (line);
}

static int	read_input(char **text, t_stack *stack)
{
	char	buf[20];
	int		buf_size;
	int		i;

	buf_size = read(0, buf, 10);
	if (buf_size < 0)
	{
		free(*text);
		ft_error(stack);
	}
	else if (buf_size == 0)
		return (1);
	buf[buf_size] = '\0';
	*text = ft_strcat(*text, buf);
	return (0);
}

char	*get_next_line(t_stack *stack)
{
	static char	*text;
	char		*result;
	int			end;

	if (!text)
		text = malloc(sizeof(char) * 20);
	if (!text)
		ft_error(stack);
	if (!ft_strchr(text, '\n'))
		end = read_input(&text, stack);
	else
		end = 0;
	if (end)
	{
		free(text);
		return (NULL);
	}
	result = get_one_line(&text);
	if (!result)
	{
		free(text);
		ft_error(stack);
	}
	return (result);
}
