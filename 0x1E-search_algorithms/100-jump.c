#include "search_algos.h"

/**
  * jump_search - func
  * @array:arg1
  * @size: arg2
  * @value:arg3
  *
  * Return: int
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, my_jump, my_step;

	if (array == NULL || size == 0)
		return (-1);

	my_step = sqrt(size);
	for (i = my_jump = 0; my_jump < size && array[my_jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", my_jump, array[my_jump]);
		i = my_jump;
		my_jump += my_step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, my_jump);

	my_jump = my_jump < size - 1 ? my_jump : size - 1;
	for (; i < my_jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
