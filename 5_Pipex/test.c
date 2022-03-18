#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig)
{
	printf("child\tchild caught sig : %d\n", sig);
	sleep(10);
	exit(1);
}

int main(int ac, char *av[])
{
	int		status;
	pid_t	pid;
	pid_t	wait_return;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid > 0)
	{
		printf("parent\tparent PID : %ld\n", (long)getpid());
		wait_return = waitpid(pid, &status, WUNTRACED);
		printf("parent\tstop wait_return is : %ld\n", (long)wait_return);
		if (WIFSTOPPED(status))
			printf("parent\tchild stopped, signal_num : %d\n", WTERMSIG(status));
		sleep(5);
		wait_return = waitpid(pid, &status, WCONTINUED | WNOHANG);
		printf("parent\tcontinue wait_return is : %ld\n", (long)wait_return);
		if (WIFCONTINUED(status))
			printf("parent\tchild continued, signal_num : %d\n", WTERMSIG(status));
	}
	else if (pid == 0)
	{
		signal(SIGCONT, sig_handler);
		printf("child\tchild PID : %ld\n", (long)getpid());
		while (1);
	}
	else
		perror("fork error : ");
	return (0);
}