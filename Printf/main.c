#include "./src/libftprintf.h"
int	main()
{
	int temp = INT_MAX;
	printf("\n%d\n", printf("123%*d", 4096, 123));
	printf("\n%d\n", ft_printf("123%*d", 4096, 123));
	return 0;
}