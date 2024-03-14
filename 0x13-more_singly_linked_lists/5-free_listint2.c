#include "lists.h"

/**
 * free_listint2 - it frees a linked_list
 * @head: the pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *help;

	if (head == NULL)
		return;

	while (*head)
	{
		help = (*head)->next;
		free(*head);
		*head = help;
	}

	*head = NULL;
}

