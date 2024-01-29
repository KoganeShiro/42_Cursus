/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

void	ft_fizzbuzz(void)
{
	int	i;
	int	j;

	i = 10;
	while (i < 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			j = i / 10 + '0';
			write(1, &j, 1);
			j = i % 10 + '0';
			write(1, &j, 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			j = i % 10 + '0';
			write(1, &j, 1);
		}
		i++;
		write(1, "\n", 1);
	}
	ft_fizzbuzz();
	write(1, "buzz\n", 5);
	return (0);
}
