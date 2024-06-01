/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int	isDuplicate(char *str, char i_union, int index)
{
	int	i;
	
	i = 0;
	while (i < index)
	{
		if (str[i] == i_union)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{	
	int i = 0;
	int j = 0;
	
	if (argc == 3)
	{
		while(argv[1][i] != '\0')
			i++;
		while(argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--;
		j = 0;
		while(j <= i)
		{
			if (!isDuplicate(argv[1], argv[1][j], j))
				write (1, &argv[1][j], 1); 
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
