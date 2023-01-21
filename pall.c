#include "monty.h"

/**
 * pall - performs the pall operation
 * @stack: the stack
 * @line_number: the number of the line
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	aux = *stack;
	printf("%d\n", aux->n);
	printf("%u\n", line_number);
}
