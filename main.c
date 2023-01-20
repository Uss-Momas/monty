#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include "monty.h"

char *line;

int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len = 0;
	ssize_t nread;
	stack_t *head = NULL;

	line = NULL;

	if (argc != 2) 
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1) {
		printf("Retrieved line of length %lu:\n", nread);
		/*printline(line);*/
		handleline(line);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}


void printline(char *l)
{
	printf("Linha: %s", l);
}

void handleline(char *l)
{
	char *token;
	int i, flag = 0;
	instruction_t operators [] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	token = strtok(l, " ");
	while (token != NULL)
	{
		printf("token: %s ",token);
		for (i = 0; operators[i].opcode != NULL; i++)
		{
			if (strcmp(token, operators[i].opcode) == 0)
			{
				/*"Opcode is right!"*/
				flag = 1;
				break;
			}
			flag = 0;
		}
		if (flag == 1)
		{
			if (strcmp(operators[i].opcode, "push") == 0)
			{
				/*Push function to be executed*/
				token = strtok(NULL, " ");
				if (token == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", 0);
					exit(EXIT_FAILURE);
				}
				/*if it's a digit than the usage: push int is right*/
				if (isdigit(*token))
				{
					printf("Token %d Is digit.\n", atoi(token));
					/*Push into the stack*/
					break;
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", 0);
					exit(EXIT_FAILURE);
				}
				break;
			}
			else if(strcmp(operators[i].opcode, "pall") == 0)
			{
				printf("Pall function to be executed:\n");
				break;
			}
		}
		token = strtok(NULL, " ");
	}
	for (i = 0; operators[i].opcode != NULL; i++)
	{
	}
}

void push(stack_t **stack, unsigned int line_number)
{
}

void pall(stack_t **stack, unsigned int line_number)
{
}
