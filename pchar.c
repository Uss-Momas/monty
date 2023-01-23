#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: the pointer to the stack
 * @ln: the line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
