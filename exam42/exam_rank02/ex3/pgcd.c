/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

//subtractive GCD algorithm

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv)
{
	int nbr1;
	int nbr2;

	if (argc == 3)
	{
		if ((nbr1 = atoi(argv[1])) > 0 && (nbr2 = atoi(argv[2])) > 0)
		{
			while (nbr1 != nbr2)
			{
				if (nbr1 > nbr2)
					nbr1 -= nbr2;
				else
					nbr2 -= nbr1;
			}
			printf("%d", nbr1);
		}
	}
	printf("\n");
	return (0);
}


/*
---> LCM (Least Common Multiple): 
The LCM of two numbers is the smallest multiple that both numbers share. 
It's the smallest positive integer that is divisible by both numbers without leaving a remainder.

---> PGCD (Greatest Common Divisor): 
The GCD of two numbers is the largest positive integer that divides both numbers without leaving a remainder.

Let's reconsider the example with a = 20 and b = 30:

    Divisors of 20: 1, 2, 4, 5, 10, 20
    Divisors of 30: 1, 2, 3, 5, 6, 10, 15, 30

The common divisors of 20 and 30 are 1, 2, 5, and 10.

    LCM (Least Common Multiple): The LCM of 20 and 30 is the smallest multiple that both numbers share. 
    The LCM of 20 and 30 is 60 because it is the smallest number that both 20 and 30 divide evenly (20 * 3 = 60, 30 * 2 = 60).

    GCD (Greatest Common Divisor): The GCD of 20 and 30 is the largest positive integer that divides 
    both numbers without leaving a remainder. The GCD of 20 and 30 is 10, 
    which is the greatest common divisor they share among all the divisors listed.

Therefore, for a = 20 and b = 30:

    LCM(20, 30) = 60 (le plus petit diviseur commun)
    GCD(20, 30) = 10 (le plus grand diviseur commun)
*/
