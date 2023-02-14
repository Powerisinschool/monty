#include "monty.h"

/**
 * add_stack - Add the top two elements at the top of the stack
 * @head: Stack to add from
 *
 * Return: 0 on success
*/
int add_stack(stack_t **head)
{
    stack_t *tmp;

    if (*head == NULL || (*head)->next == NULL)
        return (-1);

    tmp = *head;
    *head = (*head)->next;
    (*head)->n += tmp->n;
    (*head)->prev = NULL;
    free(tmp);

    return (0);
}
