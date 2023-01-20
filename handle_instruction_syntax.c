#include "monty.h"
#include <ctype.h>
/**
 * handle_instruction - handles the sintax of the instruction
 * example: push <int>, pall
 * @ln: the line
 * @line_number: the number of the line
 * Return: nothing, or exit on failure
 */
void handle_instruction(char *ln, unsigned int line_number)
{
	char *token, *cp_token;
	int i;
	instruction_t operators [] = {{"push", push}, {"pall", pall}, {NULL, NULL}};

	token = strtok(ln, " ");
	cp_token = token;
	printf("%s\n", token);
	/*
	for (i = 0; token[i] != '\n'; i++)
		;
	token[i] = '\0';*/
	
	for (i = 0; operators[i].opcode != NULL; i++)
	{
		printf("%s\n", operators[i].opcode);
		if (strcmp(cp_token, operators[i].opcode) == 0)
		{
			printf("[%d] Operator found for token %s and it is %s\n", i, cp_token, operators[i].opcode);
			if (i == 0)
			{
				token = strtok(NULL, " ");
				printf("<int> : %s\n", token);
			}
		}
	}
		/*if (strcmp(token, operators[i].opcode) == 0)
		{*/
			/* "i" is going to give us the position of the instruction*/
			/*switch (i)
			{*/
				/*It means that is the push instruction*/
			/*	case 0:
					token = strtok(NULL, " ");*/
					/*push_syntax(token, line_number);*/
					/*printf("The syntax to handle is the push");
					break;
				default:
					break;
			}
		}
	}*/
	
	while (token != NULL)
	{
		token = strtok(NULL, " ");
	}
	for (i = 0; operators[i].opcode != NULL; i++)
	{
	}
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

	for (i = 0; token[i] != '\0'; i++)
	{
		if (!isdigit(token[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_number);
			exit(EXIT_FAILURE);
		}
	}
}
