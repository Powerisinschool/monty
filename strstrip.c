#include "monty.h"

/**
 * strstrip - Strip leading and trailing whitespace from a string
 * @s: String to be stripped
 *
 * Return: Stripped string
*/
char *strstrip(char *s)
{
	size_t size;
	char *end;

	size = strlen(s);

	if (!size)
		return (s);

	end = s + size - 1;
	while (end >= s && *end == ' ')
		end--;
	*(end + 1) = '\0';

	while (*s && *s == ' ')
		s++;

	return (s);
}
