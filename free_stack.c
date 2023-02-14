#include "monty.h"

/**
 * free_stack - Free a stack off memory
 * @head: The stack
 *
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	/* Go to the end  of the linked list */
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	head = NULL;
}
