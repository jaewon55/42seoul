#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
int main()
{
	printf("%d\n", printf("%10.5d\n", 123));
	return 0;
}
