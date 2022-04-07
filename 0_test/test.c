#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int	main(int ac, char **av, char **envp)
{
	char text[1024];
	int	size;
	size = read(0, text, 1024);
	text[size] = '\0';
	printf("%s\n", text);
	return (0);
}