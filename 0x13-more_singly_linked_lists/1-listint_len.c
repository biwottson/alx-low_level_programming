#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: Pointer to the head of the linked list
 *
 * Return: The number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t num_elements = 0;

	while (h != NULL)
	{
		num_elements++;
		h = h->next;
	}

	return (num_elements);
}
