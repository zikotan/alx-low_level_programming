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
	listint_t *_node, *_jump;

	if (list == NULL || size == 0)
		return (NULL);

	my_step = 0;
	my_step_size = sqrt(size);
	for (_node = _jump = list; _jump->index + 1 < size && _jump->n < value;)
	{
		_node = _jump;
		for (my_step += my_step_size; _jump->index < my_step; _jump = _jump->next)
		{
			if (_jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", _jump->index, _jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			_node->index, _jump->index);

	for (; _node->index < _jump->index && _node->n < value; _node = _node->next)
		printf("Value checked at index [%ld] = [%d]\n", _node->index, _node->n);
	printf("Value checked at index [%ld] = [%d]\n", _node->index, _node->n);

	return (_node->n == value ? _node : NULL);
}
