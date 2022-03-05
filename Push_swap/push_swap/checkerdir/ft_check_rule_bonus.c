/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rule_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:15:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/05 20:11:28 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static int	ft_execute_rule(t_stack *stack, char *rule)
{
	if (rule[0] == 's' && !rule[2])
		return (ft_swap_rule(stack, rule));
	else if (rule[0] == 'p' && !rule[2])
		return (ft_push_rule(stack, rule));
	else if (rule[0] == 'r')
	{
		if (!rule[2])
			return (ft_rot_rule(stack, rule));
		else if (rule[1] == 'r' && !rule[3])
			return (ft_rrot_rule(stack, rule));
	}
	return (0);
}

static char	*sorted_check(t_stack *stack)
{
	int		small_num;
	t_list	*tmp;

	if (stack->b_len || !stack->top_a)
		return ("KO\n");
	small_num = stack->top_a->content;
	tmp = stack->top_a->next;
	while (tmp != stack->top_a)
	{
		if (small_num > tmp->content)
			return ("KO\n");
		small_num = tmp->content;
		tmp = tmp->next;
	}
	return ("OK\n");
}

char	*ft_check_rule(t_stack *stack)
{
	char	*rule;

	rule = get_next_line(stack);
	while (rule)
	{
		if (!ft_execute_rule(stack, rule))
		{
			free(rule);
			ft_error(stack);
		}
		free(rule);
		rule = get_next_line(stack);
	}
	return (sorted_check(stack));
}
