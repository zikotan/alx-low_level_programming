#include <stdlib.h>
#include "lists.h"

/**
 * free_list - it frees a linked list
 * @head: the list to be freed
 */
void free_list(list_t *head)
{
	list_t *temp_l;

	while (head)
	{
		temp_l = head->next;
		free(head->str);
		free(head);
		head = temp_l;
	}
}

