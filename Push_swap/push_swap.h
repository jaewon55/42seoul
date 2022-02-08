/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:26:08 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/08 16:26:08 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
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

#endif