#include "stdio.h"
#include "mandatory/libftprintf.h"
#include "limits.h"

int	main()
{
	printf("\n%d\n", printf(" %p %p", (void *)-1, (void *)ULONG_MAX));
	printf("\n%d\n", ft_printf(" %p %p", (void *)-1, (void *)ULONG_MAX));
	return 0;
}