#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	tmp[1024];
	int		size;
	int fd = open("infile", O_RDWR);
	size = 1;
	while (size > 0)
		size = read(fd, tmp, 1024);
	write(fd, "hello\n", 6);
	close(fd);
	return(0);
}
