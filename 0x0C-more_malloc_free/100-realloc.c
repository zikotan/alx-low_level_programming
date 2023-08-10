#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory using malloc and free
 * @ptr: a pointer to the memory previously allocated
 * @old_size: the size of the allocated memory for ptr
 * @new_size: the new size of the new memory
 *
 * Return: a pointer to the new allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p1;
	char *old_p;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	p1 = malloc(new_size);
	if (!p1)
		return (NULL);

	old_p = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			p1[i] = old_p[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p1[i] = old_p[i];
	}

	free(ptr);
	return (p1);
}

