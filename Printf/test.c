#include <stdio.h>
#include <limits.h>
#include <unistd.h>
int	main()
{
	write(1, "test\n", 5);
	return 0;
}
