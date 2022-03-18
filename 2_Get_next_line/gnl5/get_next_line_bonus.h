/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:23:53 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/14 17:23:54 by jaewchoi         ###   ########.fr       */
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
char	*get_next_line(int fd);
t_list	*ft_add_list(int fd, t_list *list);
char	*read_line(int fd, char *text);
char	*get_one_line(char *str);
char	*get_new_text(char *str);
size_t	ft_strlen(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(const char *s1);
t_list	*ft_del_list(t_list *list, t_list *del_list);

#endif
