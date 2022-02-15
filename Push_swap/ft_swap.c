/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:23:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/02/15 21:40:01 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_swap(t_stack *stack, t_list *a, t_list *b, int tmp)
{
	a->content = b->content;
	b->content = tmp;
}

// 두 수가 떨어져 있는가?
// 떨어져 있다면 안쪽 바깥쪽 어디가 더 적은가?
// 	-> 안쪽 : 사이의 값을 끝으로 이동하는데 ra/rra * y-> pb * x -> rra sa ra -> pa * x -> ra/rra * y
// 	-> 바깥쪽 : 사이의 값을 끝으로 이동하는데 ra/rra * y-> pb * x -> rra sa ra -> pa * x -> ra/rra * y
// 붙어 있다면 왼쪽값을 top으로 이동시키는데 ra/rra 뭐가 빠른가?
// 	-> ra : ra * y -> sa -> rra * y
// 	-> rra : rra * y -> sa -> ra * y
