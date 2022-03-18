/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:53:52 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/10 16:56:35 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;
t_list	*next(t_list *list, t_list *temp);
char	*get_next_line(int fd);
t_list	*get_text(int fd, t_list *list);
char	*read_line(int fd, char *text);
char	*get_one_line(char *str);
char	*get_new_text(char *str, t_list *list);
void	*ft_del(t_list *list);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);

#endif
