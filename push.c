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
	token = strtok(cp_line, " ");
	token = strtok(NULL, " ");
	push_syntax(token, line_number);
	number = atoi(token);
	addnode(stack, number);
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
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
}
