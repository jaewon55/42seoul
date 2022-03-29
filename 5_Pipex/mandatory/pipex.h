/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:25:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 05:36:47 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>


typedef struct s_fildes
{
	int		file_fd;
	int		pipe_fd[2];
}	t_fildes;
typedef struct s_stack
{
	size_t	a_len;
	size_t	b_len;
	int		*sorted_arr;
}	t_stack;
t_fildes	ft_open_fd(char *infile);

#endif
