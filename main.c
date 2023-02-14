#include "monty.h"

int isNumber(char *str);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: Status Code
*/
int main(int argc, char **argv)
{
	FILE *fp;
	char buff[255];
	char *line;
	int lineNumber = 0;
	stack_t *head = NULL;

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

	while (fgets(buff, 255, fp))
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
			head = push_stack(&head, atoi(line));
		} else if (strcmp(line, "pall") == 0)
		{
			print_stack((const stack_t *)head);
		} else if (strcmp(line, "pint") == 0)
		{
			printf("%i\n", head->n);
		} else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", lineNumber, line);
			return (EXIT_FAILURE);
		}
	}

	fclose(fp);

	return (0);
}

/**
 * isNumber - Check if a string contains only digits
 * @str: String to be checked
 *
 * Return: 0 if contains only digits and -1 if it does not
*/
int isNumber(char *str)
{
	while (*str++)
		if (*str < '0' || *str > '0')
			return (-1);
	return (0);
}
