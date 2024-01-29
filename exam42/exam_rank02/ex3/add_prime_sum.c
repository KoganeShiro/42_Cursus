/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <string.h>

long	ft_atoi(char *number)
{
	long	n;
	int	i;
	
	n = 0;
	i = 0;
	while (number[i] != '\0')
	{
		if (number[i] == '-')
			return (-1);
		i++;
	}
	i = 0;
	while (number[i] >= '0' && number[i] <= '9')
	{
		n = n * 10 + number[i] - '0';
		i++;
	}
	return (n);
}
/*
int	is_prime(long n)
{
	int	prime;
	int	is_prime_or;
	int	i;
	
	prime = n;
	while (prime >= 2)
	{
		is_prime_or = 1;
		i = 2;
		while (i <= (prime / 2))
		{
			if (prime % i == 0)
			{
				is_prime_or = 0;
				break;
			}
			i++;
		}
		if (is_prime_or == 1)
			return (i);
		prime--;
	}
	return (0);
}
*/

int	is_prime(int num)
{
	int	i = 2;

	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(long res)
{
	char	digit_char;
	
	if (res > 9)
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
	else
	{
		digit_char = (res + '0');
		write(1, &digit_char, 1);
	}
}

int	main(int argc, char **argv)
{
	long	n;
	long	res;
	
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		res = 0;
		while (n > 0)
		{
			if (is_prime(n) != 0)
				res += n;
			n--;
		}
		ft_putnbr(res);
	}
	if (argc != 2 || n < 0)
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

/*
#include <stdio.h>

int	main ()
{
	long	n = 5;
	
	printf("%lu\n", ft_atoi("5"));
	printf("%d", is_prime(n));
}
*/
