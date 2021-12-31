#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
int main()
{
	printf("%d\n", printf("%020d\n", 123));
	printf("%d\n", printf("%10.5i\n", 123));
	printf("%d\n", printf("%10s\n", "test123456789"));
	return 0;
}
