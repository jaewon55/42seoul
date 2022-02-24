#include <stdio.h>
#include <unistd.h>
int	main(int ac, char *av[])
{
	size_t	i = 0;

	while (i++ < 0)
		printf("%zd\t", i);
	printf("\n%zd\n", i);
	while (--i > 0)
		printf ("%zd\t", i);
	printf("\n%zd\n", i);
	return 0;
}