#include "monty.h"

/**
 * push - performs the push operation
 * @stack: the stack
 * @line_number: the number of the line
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	aux = *stack;
	printf("%d\n", aux->n);
	printf("%u\n", line_number);
}
