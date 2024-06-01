/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

void sort_int_tab(int *tab, unsigned int size)
{
	int	i = 0;
	int	tmp;
	
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
/*
#include <stdio.h>

int		main(void)
{
	int tab[] = { -1, 6, 7, 3, -6, 7, 2, 4, 5, 2147483647, -2147483648 };
	unsigned int size = 9;

	sort_int_tab(tab, size);
	unsigned int i = 0;
	while (i < size)
	{
		printf("element %d: %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
*/
