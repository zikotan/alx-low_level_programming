#include "lists.h"
#include <stdio.h>

size_t length(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * length - it counts the number of unique nodes in looped linked_list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: 0 if the list is not looped.
 * Otherwise the number of unique nodes in the list.
 */
size_t length(const listint_t *head)
{
	const listint_t *help, *h;
	size_t nd = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	help = head->next;
	h = (head->next)->next;

	while (h)
	{
		if (help == h)
		{
			help = head;
			while (help != h)
			{
				nd++;
				help = help->next;
				h = h->next;
			}

			help = help->next;
			while (help != h)
			{
				nd++;
				help = help->next;
			}

			return (nd);
		}

		help = help->next;
		h = (h->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nd, i = 0;

	nd = length(head);

	if (nd == 0)
	{
		for (; head != NULL; nd++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (i = 0; i < nd; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nd);
}

