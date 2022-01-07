#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
static void	write_recursive(ssize_t nbr, int base, int *result, char specifier)
{
	char	c;
	int		temp;

	if (*result < 0)
		return ;
	if (nbr >= base)
		write_recursive(nbr / base, base, result, specifier);
	if (nbr % base >= 10)
	{
		if (specifier == 'X')
			c = 'A' + (nbr % base) - 10;
		else
			c = 'a' + (nbr % base) - 10;
	}
	else
		c = '0' + (nbr % base);
	temp = write(1, &c, 1);
	if (temp < 0)
		*result = -1;
	else
		(*result)++;
}

int	write_nbr(ssize_t nbr, int base, char specifier)
{
	int	result;

	result = 0;
	if (nbr < 0)
		nbr *= -1;
	write_recursive(nbr, base, &result, specifier);
	return (result);
}

int	main()
{
	// printf("\nlen : %d\n", printf("% d", 0));
	// printf("\nlen : %d\n", printf("%.2147483646d", 123));
	printf("%zd\n", sizeof(void *));
	return (0);
}