#include <stdlib.h>
#include "main.h"

/**
 * *mem - fills memory with a const byte
 * @s0: the memory area to be filled
 * @a: the char to copy
 * @n: the number of times to copy b
 *
 * Return: a pointer to the memory area s0
 */
char *mem(char *s0, char a, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s0[i] = a;
	}

	return (s0);
}

/**
 * *_calloc - allocates memory for an array
 * @nmemb: the number of elements in the array
 * @size: the size of each element
 *
 * Return: a pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(size * nmemb);

	if (p == NULL)
		return (NULL);

	mem(p, 0, nmemb * size);

	return (p);
}

