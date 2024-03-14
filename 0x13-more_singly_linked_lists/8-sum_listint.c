#include "lists.h"

/**
 * sum_listint - it calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: the resulting summ
 */
int sum_listint(listint_t *head)
{
	int summ = 0;
	listint_t *help = head;

	while (help)
	{
		summ += help->n;
		help = help->next;
	}

	return (summ);
}

