#include <unistd.h>
#include <stdio.h>

int main(int ac, char *av[])
{
	pid_t pid = fork();
	if (pid > 0)
	{
		printf("child PID in parent : %ld\n", (long)pid);
		printf("parent PID : %ld\n", (long)getpid());
	}
	else if (pid == 0)
		printf("child PID : %ld\n", (long)getpid());
	else
		perror("fork error : ");
	return (0);
}