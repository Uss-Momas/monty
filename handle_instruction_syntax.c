#include "monty.h"
#include <ctype.h>
/**
 * handle_instruction - handles the sintax of the instruction
 * example: push <int>, pall
 * @stack: the stack containing the values
 * @ln: the line
 * @line_number: the number of the line
 * Return: nothing, or exit on failure
 */
void handle_instruction(stack_t **stack, char *ln, unsigned int line_number)
{
	char *token, *cp_line;
	int i;
	instruction_t operators [] = {{"push", push}, {"pall", pall}, {NULL, NULL}};

	cp_line = malloc(sizeof(char) * strlen(ln));
	if (cp_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(cp_line, ln);
	token = strtok(cp_line, " ");
	for (i = 0; operators[i].opcode != NULL; i++)
	{
		if (strcmp(token, operators[i].opcode) == 0)
		{
			switch (i)
			{
				case 0:
					token = strtok(NULL, " ");
					/*printf("<int> : %s\n", token);*/
					push_syntax(token, line_number);
					*stack = NULL;
					if (*stack == NULL)
					{
					}
					break;
				case 1:
					break;
				default:
					break;
			}
		}
	}
	free(cp_line);
}


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
		if (!isdigit(token[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_number);
			exit(EXIT_FAILURE);
		}
	}
}
