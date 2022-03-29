#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char **av, char **envp)
{
	char	**path;
	int		second_input_fd;

	if (ac != 5)
		return (0);
	path = ft_get_path(envp);
	if (!path)
		exit(1);
	second_input_fd = ft_first_cmd(av, envp, path);	
}