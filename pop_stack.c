#include "monty.h"

/**
 * pop_stack - Pop an element from the top of the stack
 * @head: Stack to pop from
 *
 * Return: 0 on success
*/
int pop_stack(stack_t **head)
{
    stack_t *tmp;
    if (*head == NULL)
        return (-1);

    tmp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(tmp);
    tmp = NULL;

    return (0);
}
