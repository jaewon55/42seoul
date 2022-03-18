/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:43:39 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/13 14:43:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
char	*get_new_text(char *str, t_list *list)
{
	char	*result;
	size_t	i;

	if (str[0] && ft_strchr(str, '\n'))
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		result = ft_strdup(&str[i + 1]);
		if (!result)
			ft_del(list);
	}
	else
		result = NULL;
	free(str);
	return (result);
}

char	*get_one_line(char *str, t_list *list)
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
			return (ft_del(list));
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
	char		*temp;
	ssize_t		read_size;

	if (!text)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	read_size = BUFFER_SIZE;
	while (text && !ft_strchr(text, '\n') && read_size > 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_line < 0 || (!read_size && !text[0]))
		{
			free(text);
			text = NULL;
			break ;
		}
		temp[read_size] = '\0';
		text = ft_strjoin(text, temp);
	}
	free(temp);
	return (text);
}

t_list	*get_text(int fd, char *list)
{
	t_list		*temp;

	temp = list
	while (temp->next && temp->next->fd != fd)
		temp = temp->next;
	if (!(temp->next))
	{
		temp->next = malloc(sizeof(t_list));
		if (!(temp->next))
			return (ft_del(list));
		temp->next->fd = fd;
		temp->next->next = NULL;
		temp->next->content = read_line(fd, ft_strdup(""));
	}
	else
		temp->next->content = read_line(fd, temp->next->content);
	if (!(temp->next->content))
	{
		free(temp->next);
		temp->next = NULL;
		return (NULL);
	}
	return (temp->next);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*temp;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!list)
	{
		list = malloc(sizeof(t_list));
		list->fd = fd;
		list->next = NULL;
		list->content = read_line(fd, ft_strdup(""));
		temp = list;
	}
	else
		temp = get_text(fd, list);
	if (!temp)
		return (NULL);
	result = get_one_line(temp->content, list);
	get_new_text(temp->content, list);
	return (result);
}
