#include "monty.h"

/**
 * pall - performs the pall operation
 * @stack: the stack
 * @line_number: not used
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
