#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;
	int		status;
	char	buf[1024];
	int		size;

	pipe(fd);
	pid = fork();
	if (pid == 0) // 자식
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		char *args[3] = {"ls", NULL};
		char *test[5] = {"a", "b", "c", "/bin/ls", NULL};
		int i = 0;
		while (test[i] && execve(test[i++], args, envp));
		exit(1);
	}
	else if (pid < 0)
		exit(1);
	waitpid(pid, &status, 0);
	close(fd[1]);
	size = read(fd[0], buf, 1024);
	buf[size] = '\0';
	printf("%s", buf);
	close(fd[0]);
	return (0);
}
