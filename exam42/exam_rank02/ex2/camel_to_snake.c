/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>
/*
int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i += 2;
		else
			i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*snake;
	
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		snake = malloc((i + 1) * sizeof(char));
		if (!snake)
			return (0);
		i = 0;
		j = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				snake[j] = '_';
				argv[1][i] += 32;
				snake[j++] = argv[1][i];
			}
			else
				snake[j] = argv[1][i];
			i++;
			j++;
		}
		snake[j] = '\0';
		ft_putstr(snake);
		free(snake);
	}
	write(1, "\n", 1);
	return (0);
}
*/
int	main(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				write(1, "_", 1);
				argv[1][i] += 32;
				write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
