#include "lists.h"

/**
 * listint_len - it returns the number of elms in a linked_lists
 * @h: the linked_list of type listint_t to traverse
 *
 * Return: the number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}

	return (n);
}

