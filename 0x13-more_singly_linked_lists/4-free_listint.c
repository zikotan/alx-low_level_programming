#include "lists.h"

/**
 * free_listint - it frees a linked_list
 * @head: the listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *help;

	while (head)
	{
		help = head->next;
		free(head);
		head = help;
	}
}

