#include "main.h"

/**
 * flip_bits - it counts the number of bits to change
 * to get from one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, c = 0;
	unsigned long int now;
	unsigned long int pro = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		now = pro >> i;
		if (now & 1)
			c++;
	}

	return (c);
}

