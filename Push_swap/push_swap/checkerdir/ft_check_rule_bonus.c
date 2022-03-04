/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rule_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:15:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/04 21:40:54 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static void	*ft_execute_rule(t_stack *stack, char *rule)
{
	if (rule[0] == 's')
		return (ft_swap_rule(stack, rule));
	else if (rule[0] == 'p')
		return (ft_push_rule(stack, rule));
	else if (rule[0] == 'r')
		if (!rule[2])
			return (ft_rot_rule(stack, rule));
		else
			return (ft_rrot_rule(stack, rule));
	else
		return (NULL);
}

static char	*sorted_check(t_stack *stack)
{
	int		small_num;
	t_list	*tmp;

	if (stack->b_len)
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

static size_t	get_rule(char *rule, char *stdin)
{
	size_t	i;

	i = 0;
	while (i < 4 && stdin[i] && stdin[i] != '\n')
	{
		rule[i] = stdin[i];
		i++;
	}
	rule[i] = '\0';
	return (i);
}

char	*ft_check_rule(t_stack *stack)
{
	char	*stdin;
	char	rule[4];
	size_t	i;

	stdin = get_next_line();
	if (!stdin)
		retrun (NULL);
	i = 0;
	while (stdin[i])
	{
		i += get_rule(rule, stdin);
		if (stdin[i++] != '\n')
		{
			free(stdin);
			return ((char *)ft_del_stack(stack));
		}
		if (!ft_execute_rule(stack, rule))
		{
			free(stdin);
			return ((char *)ft_del_stack(stack));
		}
	}
	return (sorted_check(stack));
}
