#include "monty.h"

/**
 * mult - multiplies two integers
 * @stack: the head
 * @ln: the line number
 * Return: nothing
 */
void mult(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", ln);
		free(line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(temp->next)->n = (temp->next)->n * temp->n;
	*stack = temp->next;
	free(temp);
}
