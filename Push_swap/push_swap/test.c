#include "push_swap.h"
static void	print_a(t_stack *stack)
{
	t_list	*tmp;

	printf("\n\n");
	if (!(stack->top_a))
	{
		printf("stack->a is NULL\n\n");
		return ;
	}
	tmp = stack->top_a->next;
	printf("a_head : %d ", stack->top_a->content);
	while (tmp != stack->top_a)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n\n");
}

static void	print_b(t_stack *stack)
{
	t_list	*tmp;

	printf("\n\n");
	if (!(stack->top_b))
	{
		printf("stack->b is NULL\n\n");
		return ;
	}
	tmp = stack->top_b->next;
	printf("b_head : %d ", stack->top_b->content);
	while (tmp != stack->top_b)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n\n");
}

static void	print_arr(t_stack *stack)
{
	int i;

	printf("\n\n");
	i = 0;
	while (i < 100)
		printf("%d ", stack->sorted_arr[i++]);
	printf("\n\n");
}

void	test(t_stack *stack, char c)
{
	if (c == 'a')
		print_a(stack);
	else if (c == 'b')
		print_b(stack);
	else
		print_arr(stack);
}