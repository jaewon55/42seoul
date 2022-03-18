#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
int main()
{
	int	fd[4];
	fd[0] = open("line1.txt", O_RDONLY);
	fd[1] = open("line2.txt", O_RDONLY);
	fd[2] = open("line3.txt", O_RDONLY);
	fd[3] = open("line4.txt", O_RDONLY);
	char	*str1 = get_next_line(fd[0]);
	char	*str2 = get_next_line(fd[1]);
	char	*str3 = get_next_line(fd[2]);
	char	*str4 = get_next_line(fd[3]);
	while (str1 || str2 || str3 || str4)
	{
		if (str1)
		{
			printf("%s", str1);
			free(str1);
			str1 = get_next_line(fd[0]);
		}
		if (str2)
		{
			printf("%s", str2);
			free(str2);
			str2 = get_next_line(fd[1]);
		}
		if (str3)
		{
			printf("%s", str3);
			free(str3);
			str3 = get_next_line(fd[2]);
		}
		if (str4)
		{
			printf("%s", str4);
			free(str4);
			str4 = get_next_line(fd[3]);
		}
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (0);
}