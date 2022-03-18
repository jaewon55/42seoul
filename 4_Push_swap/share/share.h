/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:42:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 19:36:19 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H
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
void	*ft_stack_del(t_stack *stack);
ssize_t	ft_itoa(char **str);
size_t	ft_list_len(t_list *head);
void	*ft_list_del(t_list *head);
t_list	*ft_parsing(int ac, char *av[]);
t_list	*ft_split_list(char *str, t_list *head);
void	ft_error(t_stack *stack);
t_stack	*ft_stack_create(t_list *head);

#endif
