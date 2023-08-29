#include "lists.h"

/**
 * get_nodeint_at_index - it returns the node at a certain index in a
 * linked_list
 * @head: the first node in the linked_list
 * @index: the index of the node to return
 *
 * Return: the pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *help = head;

	while (help && i < index)
	{
		help = help->next;
		i++;
	}

	return (help ? help : NULL);
}

