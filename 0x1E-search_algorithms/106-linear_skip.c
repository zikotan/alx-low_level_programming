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
	skiplist_t *_node, *_jump;

	if (list == NULL)
		return (NULL);

	for (_node = _jump = list; _jump->next != NULL && _jump->n < value;)
	{
		_node = _jump;
		if (_jump->express != NULL)
		{
			_jump = _jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					_jump->index, _jump->n);
		}
		else
		{
			while (_jump->next != NULL)
				_jump = _jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			_node->index, _jump->index);

	for (; _node->index < _jump->index && _node->n < value; _node = _node->next)
		printf("Value checked at index [%ld] = [%d]\n", _node->index, _node->n);
	printf("Value checked at index [%ld] = [%d]\n", _node->index, _node->n);

	return (_node->n == value ? _node : NULL);
}
