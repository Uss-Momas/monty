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
	unsigned int line_number = 1;
	ssize_t nread;

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
		printf("length: %lu, line %u: %s", nread, line_number, line);
		/*Handling the line instruction only*/
		line_handling(line, line_number);
		handle_instruction(line, line_number);
		/*increase line number*/
		line_number++;
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}


void printline(char *l)
{
	printf("Linha: %s", l);
}

void push(stack_t **stack, unsigned int line_number)
{
}

void pall(stack_t **stack, unsigned int line_number)
{
}
