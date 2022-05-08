#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **t = malloc(sizeof(char *) * 10);
	t[0] = malloc(sizeof(char) * 5);
	t[1] = malloc(sizeof(char) * 5);
	t[2] = malloc(sizeof(char) * 5);
	printf("%ld\n", sizeof(t));
	printf("%ld\n", sizeof(t[0]));
	printf("%ld\n", sizeof(t[1]));
	printf("%ld\n", sizeof(t[2]));
}
