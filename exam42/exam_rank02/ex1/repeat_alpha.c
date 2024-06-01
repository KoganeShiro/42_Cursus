/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

void	ft_repeat_alpha(char *str)
{
	int	i;
	int	x;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			x = str[i] - 'a' + 1;
			while (x > 0)
			{
				write(1, &str[i], 1);
				x--;
			}
			i++;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			x = str[i] - 'A' + 1;
			while (x > 0)
			{
				write(1, &str[i], 1);
				x--;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
