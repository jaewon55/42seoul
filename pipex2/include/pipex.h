/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:57:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/16 21:47:19 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>

# include <unistd.h>
int		ft_create_exe_file(char *path);
void	ft_write_exe_file(int ac, char **av, int fd);
int		ft_exec_file(char **envp);
void	ft_perror(void);
int		ft_multiple_pipe(int ac, char **av, char **envp);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
int		ft_is_here_doc(char *first_argument);
int		ft_here_doc(int ac, char **av, char **envp);
void	ft_quotes_limiter(char *limiter, int here_doc_fd);
void	ft_unquotes_limiter(char *limiter, int here_doc_fd);
void	ft_write_stdin(char *limiter, int fd);
char	*get_next_line(void);
void	ft_write_append_exe_file(char **av, int quotes);

#endif
