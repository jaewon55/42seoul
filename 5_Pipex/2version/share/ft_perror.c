/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:08:03 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 15:54:28 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_perror(void)
{
	perror(NULL);
	unlink("/tmp/pipe_here_doc");
	unlink("/tmp/pipe_exe");
	exit(1);
}
