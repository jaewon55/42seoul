/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:25:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/01 20:26:14 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>

# define READ 0
# define WRITE 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2
typedef struct s_data
{
	char	**args;
	int		in_fd;
	int		pipe_fd[2];
}	t_data;
int		ft_first_cmd(char **av, char **envp, char **path);
char	**ft_get_path(char *envp[]);
void	ft_last_cmd(char **av, char **envp, char **path, int in_fd);
int		ft_open_file(char *file, int option);
void	ft_perror(void);
char	*ft_prog_name(char **path, char *cmd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_printf(const char *format, ...);

#endif
