/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:52:11 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/10 16:52:44 by jaewchoi         ###   ########.fr       */
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

	if (!text)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	buf_size = BUFFER_SIZE;
	while (text && !ft_strchr(text, '\n') && buf_size != 0)
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

t_list	*get_text(int fd, t_list *list)
{
	t_list			*temp;

	temp = list;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
			return ((t_list *)ft_del(list));
		temp->fd = fd;
		temp->content = ft_strdup("");
		temp->next = NULL;
	}
	temp->content = read_line(fd, temp->content);
	if (!list || list == temp)
		return (temp);
	else
		list->next = temp;
	return (list);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*result;
	t_list			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = get_text(fd, list);
	if (!list)
		return (NULL);
	temp = list;
	while (temp->fd != fd)
		temp = temp->next;
	if (!(temp->content))
	{
		list = next(list, temp);
		return (NULL);		
	}
	result = get_one_line(temp->content);
	temp->content = get_new_text(temp->content, list);
	if (!(temp->content))
		list = next(list, temp);
	return (result);
}
