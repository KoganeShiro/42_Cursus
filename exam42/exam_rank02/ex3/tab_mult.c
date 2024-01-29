/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

/*
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *argv)
{
	int	res = 0;
	int	i = 0;
	
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		res = res * 10 + argv[i] - '0';
		i++;
	}
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int	main(int argc, char **argv)
{
	int	i = 1;
	int	num;
	
	num = ft_atoi(argv[1]);
	if (argc == 2 && num *i > 999999991) //2^31 - 1
	{
		if (num > 0)
		{
			while (i < 10)
			{
				ft_putnbr(i);
				write(1, " x ", 3);
				ft_putnbr(num);
				write(1, " = ", 3);
				ft_putnbr(i * num);
				write(1, "\n", 1);
				i++;
			}
			return (0);
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/

#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	char res = n % 10 + '0';
	write(1, &res, 1);
}

int	ft_atoi(char *av)
{
	int	i = 0;
	long	res = 0;
	
	while (av[i] >= '0' && av[i] <= '9')
	{
		res = res * 10 + av[i] - '0';
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		int n = ft_atoi(argv[1]);
		int i = 1;
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(n * i);
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
}
