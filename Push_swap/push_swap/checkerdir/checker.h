/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/04 19:49:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
typedef struct s_list
{
	int				content;
	size_t			idx;
	struct s_list	*pre;
	struct s_list	*next;
}	t_list;
typedef struct s_stack
{
	t_list	*top_a;
	t_list	*top_b;
	size_t	a_len;
	size_t	b_len;
}	t_stack;
t_list	*ft_parsing(int ac, char *av[]);
t_list	*ft_split_list(char *str, t_list *head);
ssize_t	ft_itoa(char **str);
void	*ft_list_del(t_list *head);
t_stack *ft_create_stack(t_list *head);
char	*get_next_line(void);
char	*ft_strjoin(char *s1, char *s2, int s2_len);
char	*ft_strdup(const char *s1);

#endif
