#include "monty.h"

/**
 * line_handling - handles the line instructions
 * @ln: the line 
 * @line_number: the number of the line
 * Return: nothing or exit on failure
 */
void line_handling(char *ln, unsigned int line_number)
{
	char *operation[] = {"push", "pall", NULL};
	char *token;
	int i, flag = 0;

	token = strtok(ln, " ");
	if (token != NULL)
	{
		for (i = 0; token[i] != '\n'; i++);
		token[i] = '\0';
		for (i = 0; operation[i] != NULL; i++)
		{
			if (strcmp(token, operation[i]) == 0)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, ln);
		exit(EXIT_FAILURE);
	}
}
