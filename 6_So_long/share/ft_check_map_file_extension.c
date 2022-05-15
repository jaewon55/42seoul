/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file_extension.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:30:58 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 13:09:35 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_map_file_extension(char *file)
{
	int	i;

	i = -1;
	while (file[++i] != '.')
		;
	if (file[++i] != 'b')
		return (0);
	if (file[++i] != 'e')
		return (0);
	if (file[++i] != 'r')
		return (0);
	if (file[++i] != '\0')
		return (0);
	return (1);
}
