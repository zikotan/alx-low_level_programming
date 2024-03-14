#include "lists.h"

/**
 * reverse_listint - it reverses a linked_list
 * @head: the pointer to the first node in the list
 *
 * Return: the pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *list0 = NULL;
	listint_t *list1 = NULL;

	while (*head)
	{
		list1 = (*head)->next;
		(*head)->next = list0;
		list0 = *head;
		*head = list1;
	}

	*head = list0;

	return (*head);
}

