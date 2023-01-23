#define _GNU_SOURCE
#include "monty.h"
#include <ctype.h>
/**
 * line_handling - handles the line instructions
 * @ln: the line
 * @stack: the stack
 * @line_number: the number of the line
 * @stream: the file to close
 * Return: nothing or exit on failure
 */
void line_handling(char *ln, stack_t **stack, unsigned int line_number
		, FILE *stream)
{
	char *operation[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"
		, "sub", "div", "mul", "mod", "pchar", "pstr", NULL
	};
	char *token, *cp_line, *saveptr;
	int i, flag = 0, len = 0;
	instruction_t operators [] = {{"push", push}, {"pall", pall}
		, {"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add}
		, {"nop", nop}, {"sub", sub}, {"div", f_div}, {"mul", mult}, {"mod", mod}
		, {"pchar", pchar}, {"pstr", pstr}, {NULL, NULL}
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
		for (i = 0; token[i] != '\n'; i++)
			;
		token[i] = '\0';
		for (i = 0; operation[i] != NULL; i++)
		{
			if (strcmp(token, operation[i]) == 0)
			{
				flag = 1;
				operators[i].f(stack, line_number);
				break;
			}
		}
	}
	if (flag == 0)
	{
		len = strlen(cp_line);
		cp_line[len] = '\0';
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cp_line);
		free_stack(*stack);
		free(cp_line);
		free(line);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	free(cp_line);
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
		if (ln[i] == '#')
		{
			is_only_spaces = 1;
			break;
		}
		if (!isspace(ln[i]))
		{
			is_only_spaces = 0;
			break;
		}
	}
	return (is_only_spaces);
}
