/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquotes_limiter_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:15:26 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 17:16:37 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "fcntl.h"

void	ft_unquotes_limiter(char *limiter, int here_doc_fd)
{
	ft_putstr_fd("echo \"", here_doc_fd);
	if (!ft_write_stdin(limiter, here_doc_fd))
	{
		close(here_doc_fd);
		here_doc_fd = ft_create_exe_file("/tmp/pipe_here_doc", 0);
	}
	else
		ft_putstr_fd("\"", here_doc_fd);
	close(here_doc_fd);
}
