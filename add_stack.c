#include "monty.h"

/**
 * add_dnodeint_end - Add a node to the start of a linked list
 * @head: The linked list
 * @n: The value
 *
 * Return: The number of elements
 */
stack_t *add_stack(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp;

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	/* Create head if head does not exist */
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}