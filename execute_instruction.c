#include "monty.h"

/**
 * execute_instruction - it executes the right instruction
 * @stack: the pointer to the stack
 * @line_number: the number of the line
 * Return: nothing
 */
void execute_instruction(stack_t **stack, unsigned int line_number)
{
	char *token, *cp_line;
	int i;
	instruction_t operators [] = {{"push", push}, {"pall", pall}, {"pint", pint}
		, {"pop", pop}
		, {"swap", swap}
		, {"add", add}
		, {NULL, NULL}
	};


	cp_line = malloc(sizeof(char) * strlen(line));
	if (cp_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*copy the content of the line to the cp_line*/
	/* Dest: cp_line, source: line*/
	strcpy(cp_line, line);
	token = strtok(cp_line, " ");
	for (i = 0; token[i] != '\n'; i++)
		;
	token[i] = '\0';
	for (i = 0; operators[i].opcode != NULL; i++)
	{
		/*printf("token: %s\n", token);*/
		if (strcmp(token, operators[i].opcode) == 0)
		{
			operators[i].f(stack, line_number);
			break;
		}
	}
	/*free(cp_line);*/
}
