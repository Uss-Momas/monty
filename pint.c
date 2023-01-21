#include "monty.h"
/**
 * pint - prints the value in top of the stack
 * @stack: the pointer to the stack
 * @line_number: the number of the line
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
