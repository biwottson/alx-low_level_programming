#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: Pointer to the linked list of type listint_t to print.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		_putchar(h->n + '0');
		_putchar('\n');
		num++;
		h = h->next;
	}

	return (num);
}

