/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int     *ft_rrange(int start, int end)
{
	int	i = 0;
	int	len;
	int	*array;
	
	len = ft_abs((end - start)) + 1;
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (0);
	while (i < len)
	{
		if (start < end)
		{
			array[i] = end; //will print the end number to the start number
			i++;
			end--;
		}
		else //if start is a  positive number and end a negatif one
		{
			array[i] = end; //will print the negatif (end) to the start
			i++;
			end++;
		}
	}
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	int	start = 0;
	int	end = 3;
	int	i = 0;
	int	*result = ft_range(start, end);

	while (i <= abs(end - start))
	{
		printf("%i", result[i]);
		i++;
	}
	printf("\n");
	free(result);
	return (0);
}
*/
