/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int	word_count(char *str)
{
	int i = 0;
	int words = 1;
	int in_word = 0;
	
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && in_word == 0)
		{
			words++;
			in_word = 1;
		}
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && in_word == 1)
			in_word = 0;
		i++;
	}
	return (words);
}

int	ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i + 1);
}

char    **ft_split(char *str)
{
	int	i = 0;
	int	letter = 0;
	int	word = 0;
	int	len = ft_strlen(str);
	int	wc = word_count(str);
	char	**res;
	
	res = (char **)malloc(len * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	while (str[i])
	{
		letter = 0;
		res[word] = malloc(wc * sizeof(char));
		if (res == NULL)
			return (NULL);
		while (str[i] >= '!' && str[i] <= '~')
		{
			res[word][letter] = str[i];
			letter++;
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		res[word][letter] = '\0';
		word++;
	}
	res[word] = NULL;
	return (res);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	**strs;
		int	i;

		i = 0;
		strs = ft_split(argv[1]);
		while (strs[i] != 0)
		{
			printf("[%s]\n", strs[i]);
			i++;
		}
		free(strs);
	}
	return (0);
}
*/
