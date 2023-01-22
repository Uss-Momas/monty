#include "monty.h"

/**
 * add - sum of the 2 elements at the top of the list
 * @stack: pointer to the stack
 * @line_number: the number of the line
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	second->n = second->n + first->n;
	*stack = second;
	free(first);
}
