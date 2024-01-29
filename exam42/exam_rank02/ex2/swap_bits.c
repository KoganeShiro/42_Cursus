/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 */
 
 unsigned char	swap_bits(unsigned char octet)
 {
 	unsigned char	left_half;
 	unsigned char	right_half;
 	
 	left_half = octet >> 4;
 	right_half = octet << 4;
 	
 	return (left_half | right_half);
 }
