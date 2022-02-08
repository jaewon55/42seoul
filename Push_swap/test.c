#include <stdio.h>
int	main()
{
	int i[5] = {0, 2, 3, 4, 5};
	int j = 0;
	while (j < 5)
		i[j] = i[++j];
	i[j] = 0;
	j = -1;
	while (j++ < 5)
		printf("%d\n", i[j]);
	return 0;
}