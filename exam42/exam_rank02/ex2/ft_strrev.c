/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/
/*
char    *ft_strrev(char *str)
{
	int	i;
	int	j;
	char	*rev;
	
	i = 0;
	rev = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	i--;
	j = 0;
	while (str[j] != '\0')
	{
		rev[j] = str[i];
		j++;
		i--;
	}
	rev[j] = '\0';
	return (rev);
}
*/

char    *ft_strrev(char *str)
{
	int	start;
	int	end;
	char	tmp;
	
	end = 0;
	if (!str)
		return (0);
	while (str[end] != '\0')
		end++;
	end = end - 1;
	start = 0;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	//str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = "!! dlroW ,olleH";
	
	printf("%s", ft_strrev(str));
	return (0);
}
*/
