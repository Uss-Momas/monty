#include "monty.h"

/**
 * free_stack - free's the memory used by the stack
 * @head: the starting point of the stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *temp, *temp2;

	temp = head;
	while (temp != NULL)
	{
		temp2 = temp;
		free(temp2);
		temp = temp->next;
	}
}
