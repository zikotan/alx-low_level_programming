#include "lists.h"

/**
 * delete_nodeint_at_index - it deletes a node in a linked_list at a certain index
 * @head: the pointer to the first element in the list
 * @index: the index of the node to delete
 *
 * Return: it returns 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *help = *head;
	listint_t *present = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(help);
		return (1);
	}

	while (i < index - 1)
	{
		if (!help || !(help->next))
			return (-1);
		help = help->next;
		i++;
	}


	present = help->next;
	help->next = present->next;
	free(present);

	return (1);
}

