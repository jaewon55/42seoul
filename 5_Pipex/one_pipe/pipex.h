/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:25:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/30 05:26:13 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>

typedef struct s_data
{
	char	**args;
	char	*cmd;
	int		in_fd;
	int		pipe_fd[2];
}	t_data;
t_fildes	ft_open_fd(char *infile);
int			ft_first_cmd(char **av, char **envp, char **path);
char		**ft_get_path(char *envp[]);
t_fildes	ft_open_fd(char *infile);
void		ft_perror(void);
char		*ft_prog_name(char *path, char *cmd);
void		ft_second_cmd(char **av, char **envp, char **path, int in_fd);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
int			ft_printf(const char *format, ...);

#endif
