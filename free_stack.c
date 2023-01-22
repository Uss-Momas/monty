#include "monty.h"

/**
 * free_stack - free's the memory used by the stack
 * @head: the starting point of the stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
