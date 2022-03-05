/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 01:32:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/06 06:55:39 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static char	*new_text(t_stack *stack, char *text)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(sizeof(char) * 30);
	if (!new)
	{
		free(text);
		ft_error(stack);
	}
	i = 0;
	while (text[i++] != '\n');
	j = 0;
	while (text[i])
		new[j++] = text[i++];
	new[j] = '\0';
	free(text);
	return (new);
}

static char	*one_line(t_stack *stack, char *text)
{
	int		i;
	char	*line;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	// 개행이 없어서 error가 난다.
	if (text[i] == '\0')
	{
		printf("%s\n", text);
		free(text);
		ft_error(stack);
	}
	line = malloc(sizeof(char) * i);
	if (!line)
	{
		free(text);
		ft_error(stack);
	}
	i = -1;
	while (text[++i] != '\n')
		line[i] = text[i];
	line[i] = '\0';
	return (line);
}

static char	*read_line(t_stack *stack, char *text)
{
	char	buf[20];
	int		size;

	size = read(0, buf, 10);
	if (size < 0)
	{
		free(text);
		ft_error(stack);
	}
	else if (!size)
	{
		free(text);
		return (NULL);
	}	
	buf[size] = '\0';
	text = ft_strjoin(text, buf);
	if (!text)
		ft_error(stack);
	return (text);
}

char	*get_next_line(t_stack *stack)
{
	static char	*text;
	char		*result;

	if (!text)
	{
		text = malloc(sizeof(char) * 30);
		if (!text)
			ft_error(stack);
		text[0] = '\0';
	}
	if (!ft_strchr(text, '\n'))
		text = read_line(stack, text);
	if (!text)
		return (NULL);
	result = one_line(stack, text);
	text = new_text(stack, text);
	return (result);
}
