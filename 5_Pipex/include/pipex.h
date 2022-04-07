/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:25:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/07 17:21:51 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# define READ 0
# define WRITE 1
# define APPEND 2
# define STDIN 0
# define STDOUT 1
# define STDERR 2
typedef struct s_data
{
	char	*last_cmd;
	int		in_fd;
	int		pipe_fd[2];
	int		out_fd;
}	t_data;
int		ft_first_cmd(char **av, char **envp, char **path);
char	**ft_get_path(char *envp[]);
void	ft_last_cmd(char **envp, char **path, t_data data);
int		ft_open_file(char *file, int option);
void	ft_perror(void);
char	*ft_prog_name(char **path, char *cmd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_printf(const char *format, ...);
int		ft_mid_cmd(char *cmd, char **envp, char **path, int in_fd);
char	*ft_strchr(const char *s, int c);
int		ft_is_here_doc(char *first_argument);
void	ft_multiple_pipes(int ac, char **av, char **envp, char **path);

#endif
