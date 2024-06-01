/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/
/*
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	byte;
	
	i = 8;
	while (i != 0)
	{
		byte = (octet >> i & 1) + '0';
		write(1, &byte, 1);
		i--;
	}
}
*/



// The function takes a number and goes through each bit of an octet from left to right.
//Each digit in a binary number represents a power of 2, 
//from right to left: 2^7, 2^6, 2^5, 2^4, 2^3, 2^2, 2^1, and 2^0.

void	print_bits(unsigned char octet)
{
	int bit = 128 //leftmost bit, represent the largest value a bit can take 
			//(2^7 or 128 in decimal)
	int oct = octet; // 8 bits or byte

	while (bit > 0)
	{
		if (oct & bit) //if oct AND bit is equal to 1 (TRUE) at the bit position
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bit >>= 1; 	// move to the next bit towards the right 
				//(128 -> 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1)
	}
}

/*
int main()
{
	unsigned char octet = 2;
	print_bits(octet);
	return 0;
}
*/

