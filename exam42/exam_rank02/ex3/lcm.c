/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;
	
	if (a == 0 || b == 0)
		return (0);
	lcm = (a > b) ? a : b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
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

/*
int	main()
{
	unsigned int num1 = 12;
	unsigned int num2 = 15;
	unsigned int result = lcm(num1, num2);

	printf("LCM of %u and %u is %u\n", num1, num2, result);
	return (0);
}
*/
