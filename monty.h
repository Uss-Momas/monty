#ifndef _MONTY_H_
#define _MONTY_H_

/*declare libraries*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/*
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *line;


/*Defining the functions of the program*/
int count_chars(char *filename);
void printline(char *l);
void line_handling(char *l, unsigned int ln);
void handle_instruction(stack_t **stack, char *l, unsigned int line_number);
void push_syntax(char *token, unsigned int l_number);
void execute_instruction(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void addnode(stack_t **head, int n);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
#endif
