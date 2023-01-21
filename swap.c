#include "monty.h"

/**
 * swap - swaps the two elements of the stack
 * @stack: the head
 * @line_number: the line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	aux = temp->n;
	temp->n = (temp->next)->n;
	(temp->next)->n = aux;
}
