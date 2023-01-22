#define _GNU_SOURCE
#include <sys/types.h>
#include <ctype.h>
#include "monty.h"

char *line;

/**
 * main - entry point of the program
 * @argc: the number of arguments taken
 * @argv: the arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len = 0;
	unsigned int line_number = 1;
	ssize_t nread;
	stack_t *stack = NULL;

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

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		/*Handling the line*/
		line_handling(line, line_number);
		/*Handling the instruction*/
		execute_instruction(&stack, line_number);
		/*increase line number*/
		line_number++;
	}
	free(stack);
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
