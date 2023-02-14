#include "monty.h"

/**
 * mul_stack - Multiply the top element by the second at the top of the stack
 * @head: Stack to multiply from
 *
 * Return: 0 on success
*/
int mul_stack(stack_t **head)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return (-1);

	tmp = *head;
	*head = (*head)->next;
	(*head)->n *= tmp->n;
	(*head)->prev = NULL;
	free(tmp);

	return (0);
}
