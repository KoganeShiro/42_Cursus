/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100
 */
 
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	reverse;
	int		i;
	
	i = 0;
	while (i < 32)
	{
		reverse = (reverse << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (reverse);
}

/*
#include <unistd.h>
void	print_bits(unsigned char octet)
{
	int bit = 128;
	int oct = octet;

	while (bit > 0)
	{
		if (oct & bit) 
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bit >>= 1; 	
	}
}

void	print_reverse_bits(unsigned char octet)
{
	int bit = 128;
	int oct = reverse_bits(octet);

	while (bit > 0)
	{
		if (oct & bit) 
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bit >>= 1; 	
	}
}

#include <stdio.h>

int main()
{
	unsigned char oct = 'a';
	print_bits(oct);
	printf("\n");
	print_reverse_bits(oct);
	return 0;
}
*/
