#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
int main()
{
	int i = 0;
	int j = 0;
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {0,};
	while (i < 5)
		arr2[i++] = arr1[j++];
	i = 0;
	while (i < 5)
		printf("%d\n", arr2[i++]);
	// printf("%d\n", printf("%20%\n"));
	return 0;
}
