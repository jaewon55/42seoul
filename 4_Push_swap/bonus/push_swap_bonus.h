/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 19:36:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>

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
	int		*sorted_arr;
}	t_stack;
char	*ft_check_rule(t_stack *stack);
char	*get_next_line(t_stack *stack);
char	*ft_strchr(char *s, int c);
char	*ft_strcat(char *text, char *buf);
char	*ft_strjoin(char *s1, char *s2);
int		ft_push_rule(t_stack *stack, char *rule);
int		ft_rot_rule(t_stack *stack, char *rule);
int		ft_rrot_rule(t_stack *stack, char *rule);
int		ft_swap_rule(t_stack *stack, char *rule);
void	ft_error(t_stack *stack);
ssize_t	ft_itoa(char **str);
void	*ft_list_del(t_list *head);
size_t	ft_list_len(t_list *head);
t_list	*ft_parsing(int ac, char *av[]);
t_list	*ft_split_list(char *str, t_list *head);
t_stack	*ft_stack_create(t_list *head);
void	*ft_stack_del(t_stack *stack);

#endif
