/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:50:14 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 20:47:41 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strcat(char *text, char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (text[i])
		i++;
	j = 0;
	while (buf[j])
		text[i++] = buf[j++];
	text[i] = '\0';
	return (text);
}
