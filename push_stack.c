#include "monty.h"

/**
 * push_stack - Add a node to the start of a linked list
 * @head: The linked list
 * @n: The value
 *
 * Return: The number of elements
 */
stack_t *push_stack(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	return (new);
}
