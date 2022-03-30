#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int ac, char *av[], char *envp[])
{
	int acc = access(av[1], X_OK);
	perror(NULL);
	printf("%d\n", acc);
	return (0);
}