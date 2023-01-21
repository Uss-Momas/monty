#include <stdio.h>
#include <stdlib.h>


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void insert_node_beg(stack_t **head, int n);
void print_stack(stack_t *head);
int main(void)
{
	stack_t *head = NULL;

	insert_node_beg(&head, 2);
	insert_node_beg(&head, 6);
	insert_node_beg(&head, 10);
	insert_node_beg(&head, 100);
	insert_node_beg(&head, 2000);
	insert_node_beg(&head, 1231);
	insert_node_beg(&head, 102);
	print_stack(head);
}

void insert_node_beg(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

void print_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
