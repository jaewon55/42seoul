/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:07:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 21:18:50 by jaewchoi         ###   ########.fr       */
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
