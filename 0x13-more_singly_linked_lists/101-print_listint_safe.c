#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - it prints a listint_t list safely.
 * @head: the pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *tortoise, *hare;
	size_t index = 0;

	tortoise = head;
	hare = head;

	while (tortoise != NULL && hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				printf("[%p] %d\n", (void *)tortoise, tortoise->n);
				tortoise = tortoise->next;
				nodes++;
			}

			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			printf("-> [%p] %d\n", (void *)tortoise->next, tortoise->next->n);
			nodes++;
			break;
		}
	}

	if (nodes == 0)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			nodes++;
		}
	}

	return (nodes);
}
