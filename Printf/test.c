#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
// void ft2(va_list ap)
// {
// 	printf("%d\n", va_arg(ap, int));
// }

// void test(int str, ...)
// {
// 	va_list ap;
// 	va_start(ap, str);
// 	int i = 0;
// 	while (i < str)
// 	{
// 		printf("ap%d : %p\n", i + 1, ap);
// 		ft2(ap);
// 		i++;
// 	}
// }

int main()
{
	// test(5, 10, 20, 30, 40, 50);
    printf("%d\n", printf("111%d111%d111%2147483648d\n", 0, 0, 50));
    return 0;
}
