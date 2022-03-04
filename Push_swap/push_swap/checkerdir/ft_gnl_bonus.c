/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 01:32:16 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 03:34:22 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
char	*ft_strdup(char *s1)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	read_input(char *text, t_stack *stack)
{
	char	buf[1];
	int		buf_size;
	int		i;

	buf_size = 1;
	i = 0;
	while (i < 4)
	{
		buf_size = read(0, buf, 1);
		if (buf_size < 0)
			ft_error(stack);
		else if (!buf_size)
			break ;
		if (*buf == '\n')
			break ;
		text[i++] = *buf;
	}
	if (!buf_size && (i == 0 || i == 1))
		return (1);
	if (text[i] != '\n')
		ft_error(stack);
	text[i] = '\0';
	return (0);
}

char	*get_next_line(t_stack *stack)
{
	char	text[5];
	char	*result;
	int		end;
	
	end = read_input(text, stack);
	if (end)
		return (NULL);
	result = ft_strdup(text);
	if (!result)
		ft_error(stack);
	return (result);
}
