#include "monty.h"

/**
 * div_stack - Divide the second element from the top one at the top of the stack
 * @head: Stack to subtract from
 *
 * Return: 0 on success
*/
int div_stack(stack_t **head)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return (-1);

	if ((*head)->n == 0)
		return (-2);

	tmp = *head;
	*head = (*head)->next;
	(*head)->n /= tmp->n;
	(*head)->prev = NULL;
	free(tmp);

	return (0);
}
