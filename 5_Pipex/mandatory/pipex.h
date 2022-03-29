/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:25:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/29 18:55:23 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_fildes
{
	int		in_fd;
	int		pipe_fd[2];
}	t_fildes;
t_fildes	ft_open_fd(char *infile);
int			ft_first_cmd(char **av, char **envp, char **path);
char		**ft_get_path(char *envp[]);
t_fildes	ft_open_fd(char *infile);
void		ft_perror(char *msg);
char		*ft_prog_name(char *path, char *cmd);
void		ft_second_cmd(char **av, char **envp, char **path, int in_fd);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);

#endif
