#include "lists.h"

/**
 * add_nodeint - it adds a new node at the beginning of a linked_list
 * @head: the pointer to the first node in the list
 * @n: the data to insert in that new node
 *
 * Return: the pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_list;

	new_list = malloc(sizeof(listint_t));
	if (!new_list)
		return (NULL);

	new_list->n = n;
	new_list->next = *head;
	*head = new_list;

	return (new_list);
}

