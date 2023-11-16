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
	stack_t **tail;
	FILE *stream;
	char **arg;
	char *str;
	int isStack;
} global_t;

extern global_t gGlobal;

/* --------------- file.c --------------- */
FILE *openFile(int argc, char *filename);
char *readfile(FILE *stream);
char **toker(char *str, FILE *stream);

/* --------------- match.c --------------- */
int match(stack_t **head, char **arg, int line_number);
void safe_exit(stack_t *head);
void freeAll_and_exit(stack_t *head);

/* --------------- dll.c --------------- */
void free_stack(stack_t *head);

/* push */
void push(stack_t **head, unsigned int line_number);
void add_node(stack_t **head, int val);
void add_node_at_end(stack_t **head, int val);
void pall(stack_t **head, unsigned int line_number __attribute__((unused)));

/* pint */
void pint(stack_t **head, unsigned int line_number);

/* swap */
void swap(stack_t **head, unsigned int line_number);

/* pop */
void pop(stack_t **head, unsigned int line_number);

/* add */
void add(stack_t **head, unsigned int line_number);

/* sub */
void sub(stack_t **head, unsigned int line_number);

/* nop */
void nop(stack_t **head, unsigned int line_number);

/* div */
void f_div(stack_t **head, unsigned int line_number);

/* mod */
void mod(stack_t **head, unsigned int line_number);

/* mul */
void mul(stack_t **head, unsigned int line_number);

/* pchar */
void pchar(stack_t **head, unsigned int line_number);

/* pstr */
void pstr(stack_t **head, unsigned int line_number);
void pstr_t(stack_t *head);

/* rotr */
void rotr(stack_t **head, unsigned int line_number);

/* stack_queues */
void queue(stack_t **head, unsigned int line_number);
void stack(stack_t **head, unsigned int line_number);

#endif
