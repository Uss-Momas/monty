#define _GNU_SOURCE
#include "monty.h"
#include <ctype.h>
/**
 * line_handling - handles the line instructions
 * @ln: the line
 * @line_number: the number of the line
 * Return: nothing or exit on failure
 */
void line_handling(char *ln, stack_t **stack, unsigned int line_number, FILE *stream)
{
	char *operation[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"
		, "div", "mod", "pchar", NULL
	};
	char *token, *cp_line, *saveptr;
	int i, flag = 0, len = 0;
	instruction_t operators [] = {{"push", push}, {"pall", pall}, {"pint", pint}
		, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}
		, {"div", f_div}, {"mod", mod}, {"pchar", pchar}, {NULL, NULL}
	};

	cp_line = malloc(sizeof(char) * strlen(ln));
	if (cp_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(cp_line, ln);
	token = strtok_r(cp_line, " \t", &saveptr);
	/*will return 1 if it contains only spaces: and that's a good line*/
	flag = verify_spaces(ln);
	if (token != NULL)
	{
		if (token[strlen(token) - 1] == '\n')
			token[strlen(token) - 1] = '\0';
		for (i = 0; operation[i] != NULL; i++)
		{
			if (strcmp(token, operation[i]) == 0)
			{
				flag = 1;
				printf("found, operation: %s\n", operation[i]);
				/*operators[i].f(stack, line_number);*/
				/*free(cp_line);*/
				break;
				
			}
		}
	}

	if (flag == 0)
	{
		len = strlen(ln);
		cp_line[len] = '\0';
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cp_line);
		free(cp_line);
		free(line);
		free_stack(*stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
}

/**
 * verify_spaces - verifys if a line contain only spaces or not
 * @ln: the line
 * Return: 1 if the line contains only spaces and 0 if not
 */
int verify_spaces(char *ln)
{
	int is_only_spaces = 1, i;

	for (i = 0; i < (int)strlen(ln); i++)
	{
		if (!isspace(ln[i]))
		{
			is_only_spaces = 0;
			break;
		}
	}
	return (is_only_spaces);
}
