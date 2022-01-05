#include "./src/libftprintf.h"
int	main()
{
	printf("%d\n", printf("123%-*d\n", 2147483648, 123));
	printf("%d\n", ft_printf("123%-*d\n", 2147483648, 123));
	return 0;
}