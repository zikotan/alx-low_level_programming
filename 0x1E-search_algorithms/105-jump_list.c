#include "search_algos.h"

/**
  * jump_list - func
  * @list:arg1  
  * @size: arg2
  * @value:arg3 
  *
  * Return: int
  */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t my_step, my_step_size;
	listint_t *my_node, *my_jump;

	if (list == NULL || size == 0)
		return (NULL);

	my_step = 0;
	my_step_size = sqrt(size);
	for (my_node = my_jump = list; my_jump->index + 1 < size && my_jump->n < value;)
	{
		my_node = my_jump;
		for (my_step += my_step_size; my_jump->index < my_step; my_jump = my_jump->next)
		{
			if (my_jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", my_jump->index, my_jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			my_node->index, my_jump->index);

	for (; my_node->index < my_jump->index && my_node->n < value; my_node = my_node->next)
		printf("Value checked at index [%ld] = [%d]\n", my_node->index, my_node->n);
	printf("Value checked at index [%ld] = [%d]\n", my_node->index, my_node->n);

	return (my_node->n == value ? my_node : NULL);
}
