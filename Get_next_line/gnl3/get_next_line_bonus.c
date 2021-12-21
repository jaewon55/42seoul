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

char	*get_one_line(char *str)
{
	char	*result;
	size_t	i;

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

char	*get_text(t_list *list)
{
	t_list		*temp;
	t_list		*new;

	new = list;
	while (new->next)
		new = new->next;
	while (list->next && list->next->fd != new->fd)
		list = list->next;
	if (list->next == new || list == new)
		new->content = read_line(new->fd, ft_strdup(""));
	else
	{
		new->content = read_line(new->fd, list->next->content);
		temp = list->next;
		list->next = list->next->next;
		free(temp->content);
		free(temp);
	}
	return (get_one_line(new->content));
}

t_list	*ft_listnew(int fd, t_list *list)
{
	t_list	*new;
	t_list	*temp;

	new = malloc(sizeof(t_list));
	if (!new)
		return ((t_list *)ft_del(list));
	new->fd = fd;
	new->next = NULL;
	if (list)
	{
		temp = list
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		return (list);
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*temp;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = ft_listnew(fd, list);
	if (!list)
		return (NULL);
	result = get_text(list);
	temp = list;
	while (temp->fd != fd)
		temp = temp->next;
	return (result);
}
