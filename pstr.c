#include "monty.h"

/**
 * pstr - prints the string in top of the stack
 * @stack: the head
 * @ln: the line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	(void) ln;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
