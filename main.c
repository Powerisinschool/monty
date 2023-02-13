#include "monty.h"

char *strstrip(char *s);

stack_t *push(stack_t **head, const int num);

int main(int argc, char **argv)
{
    /*char *rawCommand = "   monty  dre  ";
    char *command = malloc(sizeof rawCommand);*/
    FILE *fp;
    char buff[255];
    char *line;
    int lineNumber = 0;
    stack_t *head;
    head = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while(fgets(buff, 255, fp))
    {
        lineNumber++;
        line = buff;

        while (*line++)
            if (*line == '\n')
                *line = ' ';

        line = strstrip(buff);

        strtok(line, " ");

        if (strcmp(line, "push") == 0)
        {
            line = strtok(NULL, " ");
            if (!isNumber(line))
            {
                fprintf(stderr, "L%i: usage: push integer", lineNumber);
                return (EXIT_FAILURE);
            }
            head = push(&head, atoi(line));
        } else if (strcmp(line, "pall") == 0)
        {
            print_stack((const stack_t *)head);
        } else
        {
            fprintf(stderr, "L%i: unknown instruction %s\n", lineNumber, line);
            return (EXIT_FAILURE);
        }
    }

    /*printf(*argv);
    putchar('\n');*/

    /*strip(rawCommand, command);

    printf("%s", command);*/
    fclose(fp);
    return (0);
}

char *strstrip(char *s)
{
        size_t size;
        char *end;

        size = strlen(s);

        if (!size)
                return s;

        end = s + size - 1;
        while (end >= s && *end == ' ')
                end--;
        *(end + 1) = '\0';

        while (*s && *s == ' ')
                s++;

        return s;
}

stack_t *push(stack_t **head, const int n)
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

int isNumber(char *str)
{
    while (*str++)
        if (*str < '0' || *str > '0')
            return (-1);
    return (0);
}
