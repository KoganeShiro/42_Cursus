/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int     *ft_range(int start, int end)
{
	int	len;
	int	i = 0;
	int	*array;
	
	len = ft_abs((end - start)) + 1;
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (0);
	while (i < len)
	{
		if (start < end)
		{
			array[i] = start;
			i++;
			start++;
		}
		else
		{
			array[i] = start;
			i++;
			start--;
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
