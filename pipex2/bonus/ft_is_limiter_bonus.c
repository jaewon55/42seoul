/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_limiter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:31:03 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 15:31:20 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_limiter(char *limiter, char *input)
{
	int	i;

	i = 0;
	while (limiter[i] && input[i])
	{
		if (limiter[i] != input[i])
			return (0);
		i++;
	}
	if (!limiter[i] && input[i] == '\n')
		return (1);
	return (0);
}
