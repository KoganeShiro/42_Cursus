/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int		max(int *tab, unsigned int len)
{
	int	i;
	int	max;
	
	i = 0;
	max = 0;
	if (len == 0)
		return (0);
	while(i <= len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
 		int len = atoi(argv[2][0]);
   		int i = 0;
     		int tab[len];
   		while (argv[1][i] && i <= len)
     		{
   			tab[i] = atoi(argv[1][i]);
      			i++;
		}
		int res = max(tab, (unsigned int)len);
  		printf("%d", res);
	}
	return (0);
}
*/
