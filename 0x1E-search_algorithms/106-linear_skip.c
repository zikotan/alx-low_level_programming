#include "search_algos.h"

/**
  * linear_skip - func
  * @list:arg1  
  * @value: arg2
  *
  * Return: int
  */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *my_node, *my_jump;

	if (list == NULL)
		return (NULL);

	for (my_node = my_jump = list; my_jump->next != NULL && my_jump->n < value;)
	{
		my_node = my_jump;
		if (my_jump->express != NULL)
		{
			my_jump = my_jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					my_jump->index, my_jump->n);
		}
		else
		{
			while (my_jump->next != NULL)
				my_jump = my_jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			my_node->index, my_jump->index);

	for (; my_node->index < my_jump->index && my_node->n < value; my_node = my_node->next)
		printf("Value checked at index [%ld] = [%d]\n", my_node->index, my_node->n);
	printf("Value checked at index [%ld] = [%d]\n", my_node->index, my_node->n);

	return (my_node->n == value ? my_node : NULL);
}
