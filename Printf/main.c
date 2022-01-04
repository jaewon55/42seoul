#include "./src/libftprintf.h"
int	main()
{
	printf("%d\n", printf("%d\n", 123));
	printf("%d\n", ft_printf("%d\n", 123));
	return 0;
}