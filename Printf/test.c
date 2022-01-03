#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
int main()
{
	printf("%d\n", printf("%010.d\n", 123));
	return 0;
}
