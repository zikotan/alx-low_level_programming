#include "main.h"

/**
 * print_binary - it prints the binary of a decimal number
 * @n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, c = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			putchar('1');
			c++;
		}
		else if (c)
			putchar('0');
	}
	if (!c)
		putchar('0');
}
