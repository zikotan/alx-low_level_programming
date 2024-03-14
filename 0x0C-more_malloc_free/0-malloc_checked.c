#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - allocates memory with malloc
 * @b: the number of bytes to allocate
 *
 * Return: pointer to the memory  allocated
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
