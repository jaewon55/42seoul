#include <stdio.h>
#include <unistd.h>

int	main()
{
	/*1*/printf("\nlen : %d\n", printf("%+20.*d", -10, 123));
	/*2*/printf("\nlen : %d\n", printf("%+20.-10d", 123));
	/*3*/printf("\nlen : %d\n", printf("%+20.-10.5d", 123));
	return (0);
}