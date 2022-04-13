/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:57:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/13 19:12:14 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>

# include <unistd.h>
int		ft_create_exe_file(void);
void	ft_write_exe_file(int ac, char **av, int fd);
int		ft_exec_file(char **envp);
void	ft_perror(void);

#endif
