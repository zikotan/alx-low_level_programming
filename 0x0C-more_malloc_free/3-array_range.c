#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: the minimum range of values stored
 * @max: the maximum range of values stored
 *
 * Return: a pointer to the new array
 */
int *array_range(int min, int max)
{
	int *p;
	int i, sz;

	if (min > max)
		return (NULL);

	sz = max - min + 1;

	p = malloc(sizeof(int) * sz);

	if (p == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		p[i] = min++;

	return (p);
}

