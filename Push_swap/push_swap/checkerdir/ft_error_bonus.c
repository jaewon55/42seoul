/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:58:54 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 01:00:38 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
void	ft_error(t_stack *stack)
{
	ft_del_stack(stack);
	write(2, "Error\n", 6);
	exit(-1);
}
