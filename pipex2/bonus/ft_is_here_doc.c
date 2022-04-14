/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:07:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/15 03:09:12 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_here_doc(char *first_argument)
{
	char	*tmp;

	tmp = "here_doc";
	while (*tmp && *first_argument)
	{
		if (*tmp != *first_argument)
			return (0);
		tmp++;
		first_argument++;
	}
	if (*tmp != *first_argument)
		return (0);
	return (1);
}
