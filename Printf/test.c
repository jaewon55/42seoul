#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
int main()
{
	printf("%d\n", printf("%20d123\n", 123));
	printf("%d\n", printf("%-20d123\n", 123));
	return 0;
}
