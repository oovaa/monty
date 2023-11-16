#include "monty.h"

/**
 * stack - adjust isstack variable to be 1
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void stack(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;

	gGlobal.isStack = 1;
}

/**
 * queue - adjust isstack variable to be 0
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void queue(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;

	gGlobal.isStack = 0;
}
