/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_limiter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:48:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 21:21:11 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
void	ft_quotes_limiter(char *limiter, int here_doc_fd)
{
	ft_write_stdin(limiter, here_doc_fd);
	free(limiter);
	close(here_doc_fd);
}
