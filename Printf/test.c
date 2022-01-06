#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	main()
{
	// printf("\nlen : %d\n", printf("% d", 0));
	// printf("\nlen : %d\n", printf("%.2147483646d", 123));
	char c = 0;
	printf("\nlen : %d\n", printf("%zd", write(1, &c, 1)));
	return (0);
}