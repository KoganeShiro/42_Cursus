/*
Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:
*/

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

/*
* cur.y < 0: Checks if the current y-coordinate is less than zero, ensuring the current position is within the upper boundary of the grid.

* cur.y >= size.y: Checks if the current y-coordinate is greater than or equal to the height of the grid (size.y), ensuring the current position is within the lower boundary of the grid.

* cur.x < 0: Checks if the current x-coordinate is less than zero, ensuring the current position is within the left boundary of the grid.

* cur.x >= size.x: Checks if the current x-coordinate is greater than or equal to the width of the grid (size.x), ensuring the current position is within the right boundary of the grid.
*/


void	fill(char **grid, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| grid[cur.y][cur.x] != to_fill)
		return;

	grid[cur.y][cur.x] = 'F';
	fill(grid, size, (t_point){cur.x - 1, cur.y}, to_fill); //on the left of the current position
	fill(grid, size, (t_point){cur.x + 1, cur.y}, to_fill); //on the right of the current position
	fill(grid, size, (t_point){cur.x, cur.y - 1}, to_fill); //above the current position
	fill(grid, size, (t_point){cur.x, cur.y + 1}, to_fill); //below the current position
}

void	flood_fill(char **grid, t_point size, t_point begin)
{
	fill(grid, size, begin, grid[begin.y][begin.x]);
}


/*------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
			area[i][j] = zone[i][2 * j];
	}
	return (area);
}

int main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	t_point size  = {8, 5};
	t_point begin = {2, 2};
	char **area = make_area(zone, size.x, size.y);
	flood_fill(area, size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
		printf("\n");
	}
	free(area);
	return (0);
}
*/
