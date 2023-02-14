#include "monty.h"

void reverse_stack(stack_t **stack)
{
    stack_t* current = *stack;
    stack_t* prev = NULL;
    stack_t* next = NULL;

    if (!stack || !*stack)
        return;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    *stack = prev;
}
