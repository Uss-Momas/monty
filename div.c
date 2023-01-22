#include "monty.h"

/**
 * f_div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: the pointer to the stack
 * @line_number: the number of the line
 * Return: nothing
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "l%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	second = temp->next;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n = second->n / temp->n;
	*stack = second;
	free(temp);
}
