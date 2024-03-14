#include "lists.h"

/**
 * pop_listint - it deletes the head node of a linked_list
 * @head: the pointer to the first element in the linked list
 *
 * Return: returns the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *help;
	int n;

	if (!head || !*head)
		return (0);

	n = (*head)->n;
	help = (*head)->next;
	free(*head);
	*head = help;

	return (n);
}

