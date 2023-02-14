#include "monty.h"

/**
 * pstr_stack - Print the number of elements in a linked list
 * @h: The linked list
 *
 * Return: The number of elements
 */
int pstr_stack(const stack_t *h)
{
	int i = 0;
	stack_t *curr = (stack_t *)h;

	if (h == NULL)
		return (0);

	while (curr != NULL)
	{
        if (curr->n <= 0 || curr->n > 127)
            break;
		putchar(curr->n);
		curr = curr->next;
		i++;
	}
    putchar('\n');
	return (i);
}
