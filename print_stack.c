#include "monty.h"

/**
 * print_stack - Print the number of elements in a linked list
 * @h: The linked list
 *
 * Return: The number of elements
 */
size_t print_stack(const stack_t *h)
{
	size_t i = 0;
	stack_t *curr = (stack_t *) h;

	if (h == NULL)
		return (0);

	while (curr != NULL)
	{
		printf("%i\n", curr->n);
		curr = curr->next;
		i++;
	}
	return (i);
}
