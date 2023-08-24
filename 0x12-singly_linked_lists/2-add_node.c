#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - it adds a new node at the beginning of a linked list
 * @head: the double pointer to the list_t list
 * @str: the new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_l;
	unsigned int length = 0;

	while (str[length])
		length++;

	new = malloc(sizeof(list_t));
	if (!new_l)
		return (NULL);

	new_l->str = strdup(str);
	new_l->length = length;
	new_l->next = (*head);
	(*head) = new_l;

	return (*head);
}

