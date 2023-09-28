#include "main.h"

/**
 * get_endianness - it checks if a machine is little or big endian
 * Return: it returns 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *ch = (char *) &i;

	return (*ch);
}
