/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:34:10 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/03 18:34:13 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf"
static void	fill_field(char *str, char *field, int *flags)
{
	int	i;
	int	j;
	int	blank;

	i = 0;
	blank  = flags[5] - ft_strlen(str);
	if (flags[4] && !flags[6] && !flags[0])
	{
		while (i < blank)
			field[i++] = '0';
	}
	j = 0;
	while (str[j])
		field[i++] = str[j++];
	free(str);
}
static char	*malloc_and_fill_field(char *str, int len)
{
	char	*field;
	int	i;

	field = malloc(sizeof(char) * (len + 1));
	if (!field)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
		field[i++] = ' ';
	return (field);
}

char	*get_field(char *str, int *flags)
{
	int	i;
	int	len;
	char	*field;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (flags[5] <= len)
		return (str);
	field = malloc_and_fill_field(str, flags[5]);
	if (!field)
		return (NULL);
	fill_field(str, field, flags);
	return (field);
}
