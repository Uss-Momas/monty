#include "monty.h"

/**
 * mod - function that computes rest of the division
 * @stack: pointer to the stack
 * @ln: the line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	if((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(temp->next)->n = (temp->next)->n % temp->n;
	*stack = temp->next;
	free(temp);
}
