#include "lists.h"

/**
 * find_listint_loop - it finds the loop in a linked_list
 * @head: the linked_list to search for
 *
 * Return: the address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slowly = head;
	listint_t *faster = head;

	if (!head)
		return (NULL);

	while (slowly && faster && faster->next)
	{
		faster = faster->next->next;
		slowly = slowly->next;
		if (faster == slowly)
		{
			slowly = head;
			while (slowly != faster)
			{
				slowly = slowly->next;
				faster = faster->next;
			}
			return (faster);
		}
	}

	return (NULL);
}

