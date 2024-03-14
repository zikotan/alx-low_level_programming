#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - it adds a new node at the end of a linked list
 * @head: the double pointer to the list_t list
 * @str: the string to put in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_l;
	list_t *temp_l = *head;
	unsigned int length = 0;

	while (str[length])
		length++;

	new_l = malloc(sizeof(list_t));
	if (!new_l)
		return (NULL);

	new_l->str = strdup(str);
	new_l->len = length;
	new_l->next = NULL;

	if (*head == NULL)
	{
		*head = new_l;
		return (new_l);
	}

	while (temp_l->next)
		temp_l = temp_l->next;

	temp_l->next = new_l;

	return (new_l);
}

