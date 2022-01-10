#include <stdio.h>
#include <limits.h>

int	main()
{
	printf("%ld\n", LONG_MAX);
	printf("%lld\n", LLONG_MAX);
	printf("%lu\n", ULONG_MAX);
	printf("%lu\n", (ssize_t)ULONG_MAX);
	printf("%lu\n", (size_t)ULONG_MAX);
	return 0;
}