#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>



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


/**
 * struct global_s - Structure representing global variables.
 * @first: A pointer to the first node of the doubly linked list.
 * @stream: A pointer to the file stream.
 * @av: An array of strings representing command-line arguments.
 *
 * Description: This structure holds global variables that are used
 * across different parts of the program.
 */
typedef struct global_s 
{
	stack_t **first;
	FILE *stream;
	char **av;
	int isStack;
} global_t;

extern global_t global;

/* --------------- file.c --------------- */
FILE *openFile(int argc, char *filename);
char *readfile(FILE *stream);
char **toker(char *str, FILE *stream);

/* --------------- match.c --------------- */
int match(stack_t **head, char **arg, int line_number);
void exiting(stack_t *head);

/* --------------- dll.c --------------- */
void free_stack(stack_t *head);

/* freethething */
void freeAll_and_exit(FILE *stream, char *input_str , char **arg, stack_t *head);

/* push */
void push(stack_t **full_command, unsigned int line_number);
void add_node(stack_t **head, int val);



/**
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

#endif