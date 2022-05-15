/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:20:11 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 12:07:04 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	if (str)
		write(2, str, ft_strlen(str));
	else
		perror(NULL);
	exit(1);
}
