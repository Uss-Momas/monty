#include "monty.h"

/**
 * sub - performs the subtraction operation
 * @stack: the head
 * @ln: the line number
 */
void sub(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln);
		free(line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(temp->next)->n = (temp->next)->n - temp->n;
	*stack = temp->next;
	free(temp);
}
