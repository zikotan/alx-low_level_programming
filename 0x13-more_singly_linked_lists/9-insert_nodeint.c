#include "lists.h"

/**
 * insert_nodeint_at_index - it inserts a new node in a linked_list,
 * at a given position
 * @head: the pointer to the first node in the list
 * @idx: the index where the new node is added
 * @n: the data to insert in the new node
 *
 * Return: the pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_list;
	listint_t *help = *head;

	new_list = malloc(sizeof(listint_t));
	if (!new_list || !head)
		return (NULL);

	new_list->n = n;
	new_list->next = NULL;

	if (idx == 0)
	{
		new_list->next = *head;
		*head = new_list;
		return (new_list);
	}

	for (i = 0; help && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new_list->next = help->next;
			help->next = new_list;
			return (new_list);
		}
		else
			help = help->next;
	}

	return (NULL);
}

