#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void	ft_nbr_recursive(ssize_t nbr, int base, int *result)
{
	char	c;

	if (nbr >= 10)
		ft_nbr_recursive(nbr /base, base, result);
	c = '0' + (nbr % base);
	write(1, &c, 1);
	(*result)++;
}

int	write_nbr(ssize_t nbr, int base)
{
	int	result;

	result = 0;
	if (nbr < 0)
		nbr *= -1;
	ft_nbr_recursive(nbr, base, &result);
	return (result);
}

int	main()
{
	// printf("\nlen : %d\n", printf("% d", 0));
	// printf("\nlen : %d\n", printf("%.2147483646d", 123));
	printf("\n%d\n", write_nbr(-2147483648, 10));
	return (0);
}