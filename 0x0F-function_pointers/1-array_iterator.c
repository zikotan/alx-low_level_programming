#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - it prints each array element on a new line
 * @array: the array
 * @size: the number of elements to print
 * @action: the pointer to print in regular or hex
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
