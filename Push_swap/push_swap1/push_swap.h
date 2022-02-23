/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:26:08 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/17 21:10:36 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# define TRUE 1
# define FALSE 0
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
	int		*sorted_arr;
}	t_stack;
typedef struct s_arr
{
	int	*arr;
	int	*tmp_arr;
}	t_arr;
void	ft_half_to_a(t_stack *stack, size_t pivot_idx);
void	ft_half_to_b(t_stack *stack, int pivot);
void	ft_in_swap(t_stack *stack, t_list *left, size_t in);
int		ft_list_del(t_list *head);
size_t	ft_list_len(t_list *head);
t_stack	*ft_make_stack(t_list *list);
int		*ft_merge_sort(int *arr, size_t len);
void	ft_out_swap(t_stack *stack, t_list *right, size_t out);
t_list	*ft_parsing_av(int ac, char *av[]);
void	ft_part(t_stack *stack, t_list *left, t_list *right, t_list *pivot);
void	ft_push_swap(t_stack *stack);
void	ft_putstr(char *str);
void	ft_quick_sort(t_stack *stack);
int		*ft_sorted_arr(t_stack *stack);
int		ft_split_num(char *str, t_list *head);
void	ft_stack_del(t_stack *stack);
void	ft_swap(t_stack *stack, t_list *left, t_list *right, int tmp);

#endif