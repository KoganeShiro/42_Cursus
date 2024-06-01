/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

void		rev_wstr(char *s, int first)
{
	int		start;
	int		i;

	i = 0;
	if (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			return ;
		start = i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		rev_wstr(&s[i], 0);
		write(1, &s[start], i - start);
		if (!first)
			write(1, " ", 1);
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1], 1);
	write(1, "\n", 1);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
			i++;
		while (i > 0)
		{
			int start = 0;
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			while (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				i--;
			start = i + 1;
			//int flag = start;
			while (argv[1][start] >= '!' && argv[1][start] <= '~')
			{
				write (1, &argv[1][start], 1);
				start++;
			}
			if (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				write (1, " ", 1);
		}
	}
	write (1, "\n", 1);
	return 0;
}
*/
