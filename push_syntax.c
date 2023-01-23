#include "monty.h"
#include <ctype.h>
/**
 * push_syntax - verifys the push syntax
 * @token: the token containg the possible integer number
 * @l_number: the line number
 * Return: nothing
 */
void push_syntax(char *token, unsigned int l_number)
{
	int i;

	for (i = 0; token[i] != '\n'; i++)
		;
	token[i] = '\0';
	for (i = 0; token[i] != '\0'; i++)
	{
		if (!isdigit(token[i]) && token[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_number);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
}
