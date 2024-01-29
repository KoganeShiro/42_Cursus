/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) // or (!(n % 2))
		n /= 2;
	return ((n == 1) ? 1 : 0); // or if (n == 1) return 1; else return (0);
}

/*
#include <stdio.h>

int	main ()
{
	unsigned int	n = 6;
	printf("%u", is_power_of_2(n));
	return (0);
}
*/
