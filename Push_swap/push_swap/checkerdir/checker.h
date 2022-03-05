/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/06 07:06:56 by jaewchoi         ###   ########.fr       */
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
char	*ft_check_rule(t_stack *stack);
t_stack *ft_create_stack(t_list *head);
void	*ft_del_stack(t_stack *stack);
void	ft_error(t_stack *stack);
ssize_t	ft_itoa(char **str);
void	*ft_list_del(t_list *head);
t_list	*ft_parsing(int ac, char *av[]);
int		ft_push_rule(t_stack *stack, char *rule);
int		ft_rot_rule(t_stack *stack, char *rule);
int		ft_rrot_rule(t_stack *stack, char *rule);
t_list	*ft_split_list(char *str, t_list *head);
int		ft_swap_rule(t_stack *stack, char *rule);
char	*get_next_line(t_stack *stack);
char	*ft_strchr(char *s, int c);
char	*ft_strcat(char *text, char *buf);
char	*ft_strjoin(char *s1, char *s2);

#endif
