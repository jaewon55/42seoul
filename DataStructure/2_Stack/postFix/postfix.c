#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int ft_priority(char c)
{
    if (c == '(')
        return (0);
    else if (c == '+' || c == '-')
        return (1);
    else if (c == '*' || c == '/')
        return (2);
    else if (c == ')')
        return (3);
	return (-1);
}

char	*postFix(char *str)
{
	LinkedStack	*stack;
	StackNode	*temp;
    char        *result;
	int			r_idx;
	int			s_idx;

	if (!str)
		return (NULL);
	stack = createLinkedStack();
	if (!stack)
		return (NULL);
    if (!checkBracketMatching(str))
        return (NULL);
    result = malloc(sizeof(char) * (strlen(str) + 1));
    if (!result)
	{
		deleteLinkedStack(stack);
		return (NULL);
	}
	s_idx = 0;
	r_idx = 0;
	while (str[s_idx])
    {
		if (str[s_idx] == ' ')
			s_idx++;
		// 연산자
		else if (str[s_idx] == '+' || str[s_idx] == '-' ||\
		 str[s_idx] == '*' || str[s_idx] == '/')
		{
	        while (!isLinkedStackEmpty(stack) && ft_priority(peekLS(stack)->data)\
			 > ft_priority(str[s_idx]))
			{
				temp = popLS(stack);
				result[r_idx++] = temp->data;
				free(temp);
			}
			pushLS(stack, (StackNode){str[s_idx++], NULL});
		}
		// 닫는 괄호 ')'
		else if (str[s_idx] == ')')
        {
            while (peekLS(stack)->data != '(')
			{
				temp = popLS(stack);
				result[r_idx++] = temp->data;
				free(temp);
			}
			temp = popLS(stack);
			free(temp);
			s_idx++;
        }
		// 여는 괄호 '('
		else if (str[s_idx] == '(')
			pushLS(stack, (StackNode){str[s_idx++], NULL});
		// 피연산자
		else
            result[r_idx++] = str[s_idx++];
    }
	// 스택에 남아있는거 pop
    while (!isLinkedStackEmpty(stack))
    {
        temp = popLS(stack);
        result[r_idx++] = temp->data;
        free(temp);
    }
    deleteLinkedStack(stack);
	result[r_idx] = '\0';
    return (result);
}

int main()
{
    char	*ret;
    ret = postFix("A * ( B + C )");
    printf("%s\n", ret);
	free(ret);
	ret = postFix("2 - (3 + 4) * 5");
	printf("\n");
	printf("%s\n", ret);
	free(ret);
    return (0);
}