#include "monty.h"

/**
 * push - performs the push operation
 * @stack: the stack
 * @line_number: the number of the line
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *cp_line, *token;
	int number;

	cp_line = malloc(sizeof(char) * strlen(line));
	if (cp_line == NULL)
	{
		fprintf(stderr, "Error: maloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(cp_line, line);
	token = strtok(cp_line, " \t");
	token = strtok(NULL, " \t");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(line);
		exit(EXIT_FAILURE);
	}
	push_syntax(token, line_number);
	number = atoi(token);
	addnode(stack, number);
	free(cp_line);
}


/**
 * addnode - add's a node to the stack
 * @head: the head of the stack
 * @n: the integer number to be introduced
 * Return: nothing
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
}
