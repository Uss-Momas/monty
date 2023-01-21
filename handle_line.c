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
	char *token, *cp_line;
	int i, flag = 0;

	cp_line = malloc(sizeof(char) * strlen(ln));
	if (cp_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(cp_line, ln);
	token = strtok(cp_line, " ");
	if (token != NULL)
	{
		for (i = 0; token[i] != '\n'; i++)
			;
		token[i] = '\0';
		for (i = 0; operation[i] != NULL; i++)
		{
			if (strcmp(token, operation[i]) == 0)
			{
				flag = 1;
				free(cp_line);
				break;
			}
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, ln);
		free(cp_line);
		exit(EXIT_FAILURE);
	}
}
