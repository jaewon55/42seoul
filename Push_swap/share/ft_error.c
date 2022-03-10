/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:58:54 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/08 18:08:51 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>
void	ft_error(t_stack *stack)
{
	if (stack)
		ft_stack_del(stack);
	write(2, "Error\n", 6);
	exit(1);
}
