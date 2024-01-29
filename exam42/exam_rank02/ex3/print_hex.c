/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i = 0;
	long	res = 0;
	int	sign = 1;
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	print_hex(int num, char *base)
{
	if (num >= 16)
				print_hex(num / 16, base);
	write(1, &base[num % 16], 1);
	return (num);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int num = ft_atoi(argv[1]);
		if (num >= 0)
			print_hex(num, "0123456789abcdef");
	}
	write(1, "\n", 1);
	return (0);
}
}
