/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:26:08 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/10 21:32:53 by jaewchoi         ###   ########.fr       */
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
t_list	*ft_parsing_av(int ac, char *av[]);
int		ft_split_num(char *str, t_list *head);
#endif