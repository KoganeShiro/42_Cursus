/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

static int	number_of_digit(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		result++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = number_of_digit(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i--;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

/*
#include <stdio.h>

int main()
{
	int	n = 10000;
	
	printf("digits %d\n", number_of_digit(n));
	printf("itoa, %s\n", ft_itoa(n));
	
	return (0);
}
*/
